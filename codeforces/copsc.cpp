#include<bits/stdc++.h>

using namespace std;

#define ll long long

int const lmt=1e5+6;
int const M = 1e9+7;
ll fact[lmt];

void pre(){
    fact[0]=1;
    for(int i=1; i<lmt; i++){
        fact[i] = (fact[i-1]*(i%M))%M;
    }
}

ll be(ll a,ll n){
    ll ans = 1;
    while(n){
        if(n&1){
            ans = (ans*a)%M;
        }

        a = (a*a)%M;
        n = n>>1;
    }
    return ans;
}

ll inv_mod(ll a){
    return be(a,M-2);
}

int main(){
    pre();
    ll m,k;
    cin>>m>>k;

    ll ans = ((fact[m]*inv_mod(fact[m-k])))%M;
    ans = (ans*inv_mod(fact[k]))%M;
    ans = (ans*ans)%M;
    ans = (ans*fact[k])%M;

    cout<<ans%M<<"\n";
}