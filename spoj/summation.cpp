#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int const M = 1e8+7;

ll be(ll n){
    ll res=1;
    ll a = 2;
    while(n){
        if(n&1) res = (res*a)%M;
        a = (a*a)%M;
        n = n/2;
    }
    return res;
}

int main(){
    int t; cin>>t;
    for(int j=1; j<=t; j++){
        ll n; cin>>n;
        ll ans = 0;
        ll ele;
        for(int i=0; i<n; i++){
            cin>>ele;
            ans = (ans+ele)%M;
        }

        ans = (ans*be(n-1))%M;
        cout<<"Case "<<j<<": "<<ans<<"\n";
    }
}