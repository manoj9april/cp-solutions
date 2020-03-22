#include<bits/stdc++.h>

using namespace std;
#define ll long double

int const lmt = 1001;

ll n,m,a[lmt],b[lmt];
ll eps = 1e-16;
bool ck(ll mid){
    ll mass = m+mid;
    ll fuel;
    for(int i=0; i<n; i++){
        fuel = mass/a[i];
        mass = mass-fuel;
        fuel = mass/b[i];
        mass = mass-fuel;
    }
    return (mass>=m-eps);
}

int main(){
    cout<<setprecision(15)<<fixed;
    cin>>n>>m;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=0; i<n; i++)cin>>b[i];

    ll lo=0.0,hi=1e9+1,mid;

    int cnt=100;
    while(cnt--){
        mid = (lo+hi)/2;
        if(ck(mid))hi=mid;
        else lo=mid;
    }
    //cout<<ck(lo)<<"\n";
    if(lo<=1e9){
        cout<<lo<<"\n";
    }else{
        cout<<"-1\n";
    }
}

