#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+8;

ll a[lmt],pre[lmt];
map<ll,ll> m;

int main(){
    ll n,k;
    cin>>n>>k;
    m[0]=1;
    ll ans=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pre[i] = pre[i-1]+a[i];

        ll cur =1;
        if(k==1){
            ans += m[pre[i]-cur];
        }else if(k==-1){
            ans += m[pre[i]-cur];
            ans += m[pre[i]+cur];
        }else{
            while(cur<=1e14){
                ans += m[pre[i]-cur];
                cur *= k;
            }
        }
        m[pre[i]]++;
    }
    cout<<ans<<"\n";
}