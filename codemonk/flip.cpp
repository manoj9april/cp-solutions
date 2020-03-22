#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+4;
vector<int> adj[lmt];
int val[lmt];
int flip[32];



int main(){
    int n,s; cin>>n>>s;
    int a,b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }

}