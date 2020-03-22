#include<bits/stdc++.h>

using namespace std;

#define ll long long
int const lmt = 2e5+6;

int ans[lmt];
pair<int,int> rk[lmt];
int v[lmt];

int main(){
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>rk[i].first;
        rk[i].second=i;
    }
    int a,b;
    for(int i=0; i<m; i++){
        cin>>a>>b;
        a--;b--;
        if(rk[a].first<rk[b].first){
            v[b]++;
        }else if(rk[a].first>rk[b].first){
            v[a]++;
        }
    }

    sort(rk,rk+n);
    
    int pre=0;
    ans[rk[0].second]=0;
    for(int i=1; i<n; i++){
        int pos=rk[i].second;
        if(rk[i].first>rk[i-1].first){
            ans[pos]=i;
            pre=i;
        }else{
            ans[pos]=pre;
        }
    }

    for(int i=0; i<n; i++){
        cout<<ans[i]-v[i]<<" ";
    }
    cout<<"\n";
}