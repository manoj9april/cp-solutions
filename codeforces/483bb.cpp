#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
ll x,y,c1,c2;

bool ck(ll n){
    ll a,b,ex;
    ll lm = (x*y)/__gcd(x,y);
    a = n/lm - n/x;
    b = n/lm - n/y;
    ex = n - n/lm;
    if(c1<=a && c2<=b) return true;
    else if(c1>a && c2>b){
        return (c1-a+c2-b <= ex);
    }else if(c1>a){
        return (c1-a <= ex);
    }else{
        return (c2-b <= ex);
    }
}

int main(){
    cin>>c1>>c2>>x>>y;

    ll lo=2,hi=6e9+3,mid;
    while(lo<=hi){
        mid= lo + (hi-lo)/2;
        if(ck(mid))hi=mid-1;
        else lo=mid+1;
    } 
    cout<<lo<<"\n";
}