#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll const lmt = 5e5+6;
ll spf[lmt];

void pre(){
    for(ll i=2;i<lmt; i++){
        spf[i]=i;
    }

    for(ll i=2; i<lmt; i++){
        if(spf[i]==i){
            for(ll j=2*i; j<lmt; j+=i){
                spf[j]=i;
            }
        }
    }
}

ll be(ll a,ll n){
    ll ans = 1;
    while(n){
        if(n&1){
            ans = (ans*a);
        }

        a = (a*a);
        n = n>>1;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
    pre();
    ll t; cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll nn = n;
        
        ll ans =1;
        while(n!=1){
            ll p = spf[n];
            ll cnt=0;
            while(n%p==0) {
                n /= p;
                cnt++;
            }

            ans *= (2*cnt+1);
        }

        cout<<ans<<"\n";
    }
}