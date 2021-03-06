#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int lmt=100000;

vector<int>  adj[lmt];
bool visited[lmt]; 
int leaf;

void dfsl(int p){
    visited[p]=true;
    bool isleaf=true;
    //if(adj[p].size()==0) leaf++;
    for(int c: adj[p]){
        if(!visited[c]) { dfsl(c); isleaf=false;}
    }
    if(isleaf) leaf++;
}

double dfs(int p){
    visited[p]=true;
    double ans=0;
    for(int c: adj[p]){
        if(!visited[c]){
            ans += (dfs(c) + 1.0/leaf);
        }
    }
    //int len = adj[p].size();
    //ans += len/leaf;
    return ans;
}

int main(){
    int n; cin>>n;

    int a,b;
    for(int i=1; i<n; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    leaf=0;
    memset(visited, false, sizeof visited);
    dfsl(1);
    //cout<<leaf;
    memset(visited, false, sizeof visited);
    printf("%.15f",dfs(1));

}