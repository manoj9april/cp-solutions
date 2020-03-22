#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const lmt = 1e5+4;

ll edge[lmt];
ll val[lmt];
ll sub_cnt[lmt];
vector<int > adj[lmt];


int cnt=0;
void count(int p){
    sub_cnt[p]=1;
    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        count(c);
        sub_cnt[p] += sub_cnt[c];
    }
}
long long ans;
void dfs(int p,long long dmax){
    if(dmax>val[p]){
        ans += sub_cnt[p];
    }else{
        for(int i=0; i<adj[p].size(); i++){
            int c = adj[p][i];
            dfs(c,max(dmax+edge[c],1LL*edge[c]));
        }
    }
}

int main(){
    int n; cin>>n;
    int ele;
    for(int i=1; i<=n; i++){
        cin>>val[i];
    }
    for(int i=2; i<=n; i++){
        cin>>ele>>edge[i];
        adj[ele].push_back(i);
    }

    /*
    for(int i=1; i<=n; i++){
        cout<<i<<"===";
        for(int j=0; j<adj[i].size(); j++){
            int c = adj[i][j];
            cout<<c<<" ";
        }cout<<endl;
    }
    */

    count(1);
    dfs(1,0);
    cout<<ans<<"\n";
}
