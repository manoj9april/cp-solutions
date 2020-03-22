#include<bits/stdc++.h>

using namespace std;

int const lmt=100;

vector<int> adj[lmt];
int m,n;
bool vis[lmt];
vector<int> sol;

bool dfs(int p,int cnt){
    cout<<p<<" ";
    if(vis[p]){
        if(p==1 && cnt==n+1){
            for(int i=0; i<sol.size(); i++){
                cout<<sol[i]<<" ";
            }cout<<"\n";
            return true;
        }else{
            return false;
        }
    }

    sol.push_back(p);
    vis[p]=true;
    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        if(dfs(c,cnt+1)) return true;
        
    }
    vis[p]=false;
    sol.pop_back();
    return false;
}


int main(){
    int e;
    cin>>n>>e;
    int a,b;
    memset(vis,false,sizeof vis);
    while(e--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(!dfs(1,1)) cout<<"not got\n";
}