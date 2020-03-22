#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int>   pii;

#define pb  push_back
#define mp  make_pair

int const lmt  = 1e5+1;

vector < pair<int, int> > adj[lmt];

bool vis[lmt];

int main(){
    int t; cin>>t;
    string str;
    while(t--){
        int n; cin>>n;
        for(int i=1; i<=n; i++){
            cin>>str;
            vis[i]=false;
            adj[i].clear();
            int ng; cin>>ng;
            int c,cost;
            while(ng--){
                cin>>c>>cost;
                adj[i].pb(mp(cost,c));
                adj[c].pb(mp(cost,i));
            }
        }

        multiset< pair<int, int> > q;
        q.insert(mp(0,1));   // cost  node

        int mcost=0;
        while(!q.empty()){
            pii p = *q.begin(); q.erase(q.begin());
            int node = p.second;
            if(vis[node]) continue;

            for(int i=0; i<adj[node].size(); i++){
                int c = adj[node][i].second; int wt = adj[node][i].first;
                if(!vis[c]){
                    q.insert(mp(wt,c));
                }
            }

            mcost += p.first;
            vis[node]=true;
        }

        cout<<mcost<<"\n";
    }
}