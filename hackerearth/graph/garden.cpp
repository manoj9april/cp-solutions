#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 2e3+6;

int vis[lmt],cnt[lmt],ans;
vector<int> adj[lmt];
void dfs(int p, int val){
    if(vis[p]==1){
        if(val-cnt[p]==4)ans++;
        return;
    }
    vis[p]=1;
    cnt[p]=val;
    for(auto c: adj[p]){
        if(vis[c]!=2) dfs(c,val+1);
    }
    vis[p]=2;

}
int main(){
    int n,ele; cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>ele;
            if(ele){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    memset(vis,0,sizeof vis);
    ans=0;
    dfs(1,0);
    cout<<ans<<"\n";
}