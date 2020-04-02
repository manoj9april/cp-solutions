#include<bits/stdc++.h>

using namespace std;

#define ll long long
int const lmt = 1e6+4;
ll mod = 1e9+7;

ll fact[lmt];

ll be(ll a, ll k){
    ll ans=1;
    while(k){
        if(k&1) ans = (ans* a)%mod; 

        a = (a*a)%mod;
        k = (k>>1);
    }
    return ans;
}

ll inv(ll k){
    // return k;
    return be(k,mod-2);
}


ll nCr(ll n, ll r){
    ll ans = fact[n]%mod;
    ans = (ans*inv(fact[r]))%mod;
    ans = (ans*inv(fact[n-r]))%mod;

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);


    // #ifndef ONLINE_JUDGE
    // freopen("./input.txt", "r", stdin);
    // freopen("./output.txt", "w", stdout);
	// #endif
    
    fact[0]=1;
    for(ll i=1; i<lmt; i++){
        fact[i] = (fact[i-1]*i)%mod;
    }
    
    ll t; cin>>t;
    while(t--){
        ll a,b,m,n;
        cin>>a>>b>>n>>m;
        
        ll val_a,val_b;
        if(n+1==m) val_a =0, val_b=1;
        else if(m==1) val_a=1, val_b=0;
        else{
            n--; m--;
            val_a  = nCr(n,m);
            val_b = nCr(n,m-1);
        }
        ll ans = (a*val_a + b* val_b)%mod ;
        cout<< ans <<"\n";
    }
}


