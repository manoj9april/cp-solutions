#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<pair<int, int> > adj[100005];   //  edge weight   ,  child node
bool visited[100005];
int dist[100005];
int v2;


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
        visited[p.S]=true;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n,m,src,dst;
        cin>>n>>m>>src>>dst;
        v2=dst;

        for (int i = 0; i < n+1; i++)
        {
            adj[i].clear();
            dist[i]=200000000;
            visited[i]=false;
        }
        

        for(int i=0; i<m; i++){
            int a,b,time;
            cin>>a>>b>>time;
            adj[a].pb(mp(time,b));
            adj[b].pb(mp(time,a));
        }
        
        
        
        djk(src);
        if(dist[dst]==200000000){
            cout<<"NONE\n";
        }else{
            cout<<dist[dst]<<"\n";
        }
    }
}