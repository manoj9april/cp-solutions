#include <bits/stdc++.h>

using namespace std;

typedef long long  ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        ll ans=0;
        ll lo=0,hi=sqrt(n);
        bool found=false;
        while(lo<=hi){
            ans = lo*lo + hi*hi;
            if(n==ans){
                found = true;
                break;
            }else if(ans>n){
                hi--;
            }else lo++;
        }

        cout<<(found?"Yes":"No")<<endl;
    }
}