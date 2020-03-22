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

multiset<pli> q;

ll prims(){
    ll min_cost=0;
       // weight , node
    

    while(!q.empty()){
        pli nd = *q.begin(); q.erase(q.begin());

        int p = nd.s;
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
    
    int n,m,ele;
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>ele;
        if(ele)  q.insert(mp(0,i));
    }
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
    cout<<prims()<<endl;
}