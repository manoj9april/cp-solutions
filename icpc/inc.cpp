#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll a[4]={2,3,11,13};
ll n;

int main(){
    cin>>n;
    ll sum=0;
    for(ll i=1; i<(1<<4); i++){
        ll p=1,cnt=0;
        for(ll j=0; j<4; j++){
            if((i>>j)&1){
                p *= a[j];
                cnt++;
            }
        }
        if(cnt%2) sum += (n/p);
        else sum -= (n/p);
    }
    ll g = __gcd(sum,n);
    cout<<sum/g<<" "<<n/g<<"\n";
}