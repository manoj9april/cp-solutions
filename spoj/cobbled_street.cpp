#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll , int > pli;

#define mp  make_pair
#define pb  push_back
#define f first
#define s second

const int lmt = 1e4 +7;

vector<pli> adj[lmt];  // weight , node
bool added[lmt];

ll prims(int p){
    ll min_cost=0;
    multiset<pli> q;   // weight , node
    q.insert(mp(0,p));

    while(!q.empty()){
        pli nd = *q.begin(); q.erase(q.begin());

        p = nd.s;
        if(!added[p]){
            min_cost += nd.f;
            for(pli c : adj[p]){
                if(!added[c.s]){
                    q.insert(c);
                }
            }

            added[p] = true;
        }
    }

    return min_cost;
}

int main(){
    int t; cin>>t;
    while(t--){

        int n,m,price;
        cin>>price>>n>>m;

        for(int i=0; i<=n; i++){
            adj[i].clear();
        }
        memset(added , false, sizeof added);
        
        int a,b;
        ll w;
        while(m--){
            cin>>a>>b>>w;
            adj[a].pb(mp(w,b));
            adj[b].pb(mp(w,a));
        }
        cout<<price*prims(a)<<endl;

    }
}