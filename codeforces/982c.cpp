#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+6;

vector<int> adj[lmt];

int cnt[lmt];
int ans = -1;

void sub_cnt(int p, int par){
    cnt[p]=1;

    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        if(c!=par){
            sub_cnt(c,p);
            cnt[p] += cnt[c];
        }
    }

    if(cnt[p]%2==0) ans++;
}

int main(){
    int n; cin>>n;

    int a,b;
    for(int i=0; i<n-1; i++){
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    if(n%2==1){
        cout<<-1<<"\n";
        return 0;
    }
    sub_cnt(1,0);

    cout<<ans<<"\n";
}