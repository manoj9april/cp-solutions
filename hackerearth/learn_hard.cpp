#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e3+3;
int val[lmt];
vector<int> adj[lmt];

bool comp(int a, int b){
    if(val[a]==val[b]) return a>b;

    return val[a]>val[b];
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int a,b;
    for(int i=1; i<=n; i++)cin>>val[i];
    for(int i=0; i<m; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        sort(adj[i].begin(),adj[i].end(),comp);
        if(k<=adj[i].size())
            cout<<adj[i][k-1]<<"\n";
        else cout<<"-1\n";
    }

}