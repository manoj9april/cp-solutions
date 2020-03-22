#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<pair<int, int>> adj[10005];
bool visited[10005];
int cst[10005];
int v1, v2;
set<pair<int, int>> scv;

void djk(int v1)
{
    cst[v1] = 0;
    queue<pair<int, int>> q;
    auto it = scv.begin();scv.erase(it);
    visited[v1]=true;
    q.push(mp(0, v1));

    while (!q.empty())
    {
        it = scv.begin();scv.erase(it);
        pair<int,int> pp = *it;
        q.push(pp);
        visited[pp.S] = true;
        pair<int, int> p = q.front();
        q.pop();

        for (auto x : adj[p.S])
        {
            if (!visited[x.S])
            {
                cst[x.S] = min((cst[p.S] + x.F), cst[x.S]);
            }

            /*q.push(x);
            visited[x.F] = true;
            if (x.F == v2)
                goto lb;*/
        }
        
    }

    lb:;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        for (int i = 0; i < 10005; i++)
        {
            adj[i].clear();
        }
        //q.clear();
        int n;
        cin >> n;
        string s[n];
        for (int i = 0; i < n; i++)
        {
            v1 = i + 1;
            cin >> s[i];
            int nbr;
            cin >> nbr;
            for (int j = 0; j < nbr; j++)
            {
                int cost;
                cin >> v2 >> cost;
                adj[v1].pb(mp(v2, cost));
            }
        }

        int paths;
        cin >> paths;
        for (int i = 0; i < paths; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            for (int j = 0; j < n; j++)
            {
                if (c1 == s[j])
                    v1 = j + 1;
                if (c2 == s[j])
                    v2 = j + 1;
            }

            memset(visited, false, sizeof(visited));
            memset(cst, INT_MAX, sizeof(cst));
            scv.clear();
            for(int j=1; j<=n; j++){
                scv.insert(mp(cst[j],j));
            }

            djk(v1);
            cout << cst[v2] << "\n";
            //cout<<INT_MAX<<"hellp\n";
        }
    }
}