#include<bits/stdc++.h>

#define MM 100001

using namespace std;

//class
bool vis[MM];
vector<int> nof[MM];

int dfs(int node){
    int cnt=1;

    for(auto child : nof[node]){
        if(!vis[child]){
            cnt += dfs(child);
        }
        vis[child] = true;
    }
    return cnt;
}

int main(){
    int t; cin>>t; 
    while(t--){
        int n,e,clib,croad;
        cin>>n>>e>>clib>>croad;
        
        
        int v,nbr;
        for(int i=0; i<e; i++){
            cin>>v>>nbr;
            nof[v-1].push_back(nbr-1);
        }
        
        
        memset(vis,false,n*sizeof(vis[0]));
        
        int sum=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                int noc = dfs(i);
                sum += min(noc*clib,(noc-1)*croad + clib);
            }
        }
        cout<<sum<<"\n";
    }
    
}