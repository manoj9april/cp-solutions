#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

ll const lmt =  1e5+3;
ll inf = 1e17+2;

vector<pair<ll, ll> > adj[lmt];   //  edge weight   ,  child node
bool visited[lmt];
ll dist[lmt],odd[lmt],even[lmt];
ll v1, v2;

ll n,m,k,q,a,b,c;

void djk(ll v1)
{
    
    multiset<pair<ll, ll> > q;   // distance from v1 or dist[node] ,  node
    dist[v1] = 0;
    q.insert(mp(0, v1));  // or q.insert(mp(dist[v1],v1));

    while (!q.empty())
    {
        pair<ll, ll> p = *q.begin();
        q.erase(q.begin());
	
        if(visited[v2]) break;
	
        if(!visited[p.S]){
            for (auto x : adj[p.S])
            {
                if (dist[p.S] + x.F < dist[x.S])
                {
                    dist[x.S] = (dist[p.S] + x.F );
                    if((x.F&1)){
                        odd[x.S] = odd[p.S]+x.F;
                        even[x.S]=even[p.S];
                    }else{
                        odd[x.S] = odd[p.S];
                        even[x.S] = even[p.S]+x.F;
                    }
                    q.insert( mp(dist[x.S] , x.S) );
                }
            }
        }

        visited[p.S]=true;
    }
}
void ini(){
    for(int i=0; i<=n; i++){
        dist[i]=inf;
        odd[i]=even[i]=0;
        visited[i]=false;
    }
}
int main()
{
    
    cin>>n>>m>>q;
    for(ll i=0; i<m; i++){
        cin>>a>>b>>c;
        adj[a].pb({c,b});
        adj[b].pb({c,a});
    }
    while(q--){
        int type; cin>>type;
        ini();
        cin>>a>>b;
        swap(a,b);
        if(type==1){
            continue;
        }
        v2=b;
        djk(a);
        //cout<<dist[b]<<"\n";
        cout<<((dist[b]&1ll)?even[b]:odd[b])<<"\n";
    }
}