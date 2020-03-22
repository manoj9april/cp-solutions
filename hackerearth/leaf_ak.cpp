#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e7+2;
int mod=1e9+9;
int dp[lmt];
ll k=2;
int main(){
    ll n=1e7; //cin>>n;
    ll ans=0,j=0;
    
    for(ll i=1; j<n*n; i+=2){
        //cout<<j<<"\n";
        //cin>>ch;
        int r=4;
        for( ;r && j<=n*n; r--){
            j += i;
            ans += (j)%mod;
            ans %= mod;
            if(j>=k*k){
                dp[k]=ans;k+=2;
            }
        }
    }
    // odd
    n=1e7; //cin>>n;
    ans=1,j=1; k=3;dp[1]=1;
    
    for(ll i=2; j<n*n; i+=2){
        //cout<<j<<"\n";
        //cin>>ch;
        int r=4;
        for( ;r && j<=n*n; r--){
            j += i;
            ans += (j)%mod;
            ans %= mod;
            if(j>=k*k){
                dp[k]=ans;k+=2;
            }
        }
    }
    ll t; cin>>t;
    while(t--){
        cin>>n;
        cout<<dp[n]<<"\n";
    }
    
}