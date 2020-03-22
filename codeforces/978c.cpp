#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n,m;
int const lmt = 2e5+3;

ll a[lmt],pre[lmt];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];
    }
    ll b;
    for(int i=0; i<m; i++){
        cin>>b;
        int idx = lower_bound(pre,pre+n+1,b)-pre;
        cout<<idx<<" "<<(b-pre[idx-1])<<"\n";
    }
}