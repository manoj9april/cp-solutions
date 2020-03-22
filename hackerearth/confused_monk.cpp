#include<bits/stdc++.h>

using namespace std;

#define ll long long

int const M = 1e9+7;

ll be(ll a, ll n){
    ll ans =1;
    while(n){
        if(n&1){
            ans = (ans*a)%M;
        }

        n = n>>1;
        a = (a*a)%M;
    }
    return ans;
}

ll gcd(ll a, ll b){
    if(b==0){
        return a;
    }

    return gcd(b, a%b);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin>>n;

    int a[n];
    int g = 0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        g = gcd(g,a[i]);
        //cout<<g<<"\n";
    }

    ll ans = 1;
    for(int i=0; i<n; i++){
        ans = (ans*be(a[i],g))%M;
    }

    cout<<ans<<"\n";
}