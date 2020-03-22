#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll const m = 1e9+7;

ll be(ll n){
    ll a=2; ll ans=1;
    while(n){
        if(n&1) ans = (ans*a)%m;

        a = (a*a)%m;
        n = n/2;
    }

    return ans;
}

int main(){
    ll x,k;
    cin>>x>>k;
    if(x==0){
        cout<<0<<"\n";
        return 0;
    }
    ll ans = ((x%m)*be(k+1))%m - be(k) + 1;
    ans = (ans+m)%m;
    cout<<ans<<"\n";
}