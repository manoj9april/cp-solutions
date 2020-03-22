#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+3;
vector<int> adj[lmt];
int cnt=0;
int a[lmt],pos[lmt];
int sub[lmt];
void dfs(int p){
    pos[p]=cnt;
    a[cnt++]=p;
    sub[p]=1;
    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        dfs(c);
        sub[p]+=sub[c];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,q,par;
    cin>>n>>q;
    for(int i=2; i<=n; i++){
        cin>>par;
        adj[par].push_back(i);
    }
    dfs(1);
    int u,k;
    for(int i=0; i<q; i++){
        cin>>u>>k;
        if(sub[u]<k){
            cout<<"-1\n";
        }else{
            cout<<a[pos[u]+k-1]<<"\n";
        }
    }
}

