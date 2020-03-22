#include<bits/stdc++.h>

using namespace std;

int const lmt=100;

vector<int> adj[lmt];
int color[lmt];
int m,n;

bool dfs(int p, int cnt){

    for(int j=1; j<=m; j++){
        color[p]=j;
        bool ok=true;
        for(int i=0; i<adj[p].size(); i++){
            int c = adj[p][i];
            if(color[c]==j){
                ok=false;
                break;
            }
        }
        if(ok){
            if(cnt==n){
                for(int i=1; i<=n; i++){
                    cout<<color[i]<<" ";
                }cout<<"\n";
                return true;
            }else{
                for(int i=0; i<adj[p].size(); i++){
                    int c = adj[p][i];
                    if(color[c]==-1){
                        if(dfs(c,cnt+1)) return true;;
                    }
                }
            }
        }
    }
    color[p]=-1;
    return false;
}

int main(){
    int e;
    cin>>n>>e>>m;
    int a,b;
    memset(color,-1,sizeof color);
    while(e--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(!dfs(1,1)){
        cout<<"no sol got\n";
    }
}