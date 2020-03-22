#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<pair<int, int> > adj[10005];   //  edge weight   ,  child node
bool visited[10005];
int dist[10005];
int v1, v2;


void djk(int v1)
{
    
    multiset<pair<int, int> > q;   // distance from v1 or dist[node] ,  node
    dist[v1] = 0;
    q.insert(mp(0, v1));  // or q.insert(mp(dist[v1],v1));

    while (!q.empty())
    {
        pair<int, int> p = *q.begin();
        q.erase(q.begin());
	
        if(visited[v2]) break;
	
        if(!visited[p.S]){
            for (auto x : adj[p.S])
            {
                if (dist[p.S] + x.F < dist[x.S])
                {
                    dist[x.S] = (dist[p.S] + x.F );
                    q.insert( mp(dist[x.S] , x.S) );
                }
            }
        }

        visited[p.S]=true;
    }
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
        
        int n;
        cin >> n;
        string s;
        map<string , int> city;

        for (int i = 1; i <= n; i++)
        {
            v1 = i ;
            cin >> s;
            city[s]=i;
            int nbr;
            cin >> nbr;
            for (int j = 0; j < nbr; j++)
            {
                int cost;
                cin >> v2 >> cost;
                adj[v1].pb(mp(cost, v2));
                // adj[v2].pb(mp(cost,v1));
            }
        }

        int paths;
        cin >> paths;
        vector <int, int> query
        for (int i = 0; i < paths; i++)
        {
            string c1, c2;
            cin >> c1 >> c2;
            
            v1 = city[c1];
            v2 = city[c2];

            memset(visited, false, sizeof(visited));
            memset(dist, 200000, sizeof(dist));
            

            djk(v1);

            cout << dist[v2] << "\n";
            //cout<<200000<<"hellp\n";
        }
    }
}