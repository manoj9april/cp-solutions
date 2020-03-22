#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second

vector<int> adj[10005];
bool visited[10005];
int cnt;
void dfs(int a){
    visited[a]=true;
    cnt++;
    for(auto x:adj[a]){
        if(!visited[x]){
            dfs(x);
        }
    }
    
}

int main(){
    int n,m;int a,b;
    cnt=0;
    memset(visited,false,sizeof(visited));
    if(m!= n-1){
        
        for(int i=0;i<m; i++){
            cin>>a>>b;
        }
        cout<<"NO";
    }
    else{
        for(int i=0;i<m; i++){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        dfs(a);
        int N = cnt;
        cout<<(n==N)?"YES":"NO";
    }
}