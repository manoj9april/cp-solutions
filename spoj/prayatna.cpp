#include<bits/stdc++.h>

using namespace std;

vector<int>  adj[100002];
bool visited[100002];

void dfs(int p){
    visited[p]=true;
    for(int c : adj[p]){
        if(!visited[c]){
            dfs(c);
        }
    }
}

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;

        for(int i=0; i<=n; i++){
            adj[i].clear();
            visited[i] = false;
        }

        int m; cin>>m;
        int a,b;
        while(m--){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int cnt=0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i);
                cnt++;
            }
        }

        cout<<cnt<<endl;

    }
}