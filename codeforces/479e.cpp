#include<bits/stdc++.h>
using namespace std;


int const lmt = 1e6+4;

vector<int> adj[lmt];
bool vis[lmt];
bool ans;

void dfs(int p){
    vis[p]=true;
    if(adj[p].size()!=2) ans = false;
    for(int i=0;i<adj[p].size(); i++){
        int c=adj[p][i];
        if(!vis[c]){
            dfs(c);
        }
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    int a,b;

    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(vis,false, sizeof vis);

    int cnt=0;
    for(int i=1; i<=n; i++){

        if(!vis[i]){
            ans =true;
            dfs(i);
            cnt += ans;
            //if(ans)cout<<i<<"****\n";
        }
    }

    cout<<cnt<<"\n";
}