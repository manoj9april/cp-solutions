#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int lmt=150005;

vector<int>  adj[lmt];
bool visited[lmt]; 
int cnt;

void dfs(int p){
    visited[p]=true;

    cnt++;

    for(int c: adj[p]){
        if(!visited[c])  dfs(c);
    }
}

int main(){
    memset(visited,false, sizeof visited);
    long long m;
    int n; cin>>n>>m;
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    long long int edge=0;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cnt=0;
            dfs(i);
            edge += (long long)(1LL*cnt*(cnt-1)/2);
            if(edge>m) break;
        }
    }

    cout<<(edge==m?"YES":"NO");

}
