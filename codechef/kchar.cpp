#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long int

bool po2(ll n){
    return !(n&(n-1));
}
ll big2(ll n){
    n = (n|(n>>1));
    n = (n|(n>>2));
    n = (n|(n>>4));
    n = (n|(n>>8));
    n = (n|(n>>16));
    n = (n|(n>>32));
    //n = (n||(n>>64));
    return ((n+1)>>1);
}
int solve(ll k){
    if(po2(k)) return 0;
    ll t = big2(k);

    return (1 - solve(t-(k-t)));
}
int main(){
    int t; cin>>t;
    while(t--){
        ll k;cin>>k;
        cout<<(solve(k)?"c":"a")<<"\n";
    }
}