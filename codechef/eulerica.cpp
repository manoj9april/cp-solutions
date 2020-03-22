#include<bits/stdc++.h>

#define MOD               1000000007
#define pb                    push_back

using namespace std;

typedef long long  ll;


int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b%a, a);
}

int phi(unsigned int n)
{
    unsigned int result = 1;
    for (int i=2; i < n; i++)
        if (gcd(i, n) == 1)
            result++;
    return result;
}
int maxx;

bool visited[10005];
int path[10005];
vector<int> adj[10005];

void dfs(int u){
    visited[u] = true;

    for(int child : adj[u]){
        if(!visited[child]){
            path[child] = child + path[u];
            maxx = max(maxx,path[child]);
        }
    }
}

int main(){
    int n;cin>>n;
    
    for(int i=1; i<=n; i++){
        int pp = phi(i);
        if(i!= pp){
            adj[i].pb(pp);
        }
    }
    int t; cin>>t;
    while(t--){
        maxx = 0;
        memset(visited,false,sizeof(visited));
        int k; cin>>k;
        dfs(k);
        cout<<maxx<<"\n";
    }
}