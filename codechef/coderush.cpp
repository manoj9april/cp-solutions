#include<bits/stdc++.h>

#define MOD               1000000007

using namespace std;

typedef long long  ll;


int main(){
    int t; cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;

        ll l;

        if((b-a)%d == 0){
            l = b-d;
        }else{
            l = a + ((b-a)/d)*d;
        }
        ll n = (l-a)/d + 1;
        ll res = ((n%MOD)*((a%MOD + l%MOD)%MOD))%MOD;
        cout<<res/2<<"\n";


    }
}