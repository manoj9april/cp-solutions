#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+2;
ll d[lmt],a[lmt];
int main(){
    cout<<setprecision(15)<<fixed;
    int n,m;
    cin>>n>>m;
    ll x,di;
    ll sum=0;
    ll st=0,mid=0;
    for(int i=0; i<m; i++){
        cin>>x>>di;
        sum += x;
        if(di<0)mid+=di;
        else st+=di;
    }
    ll ans=0;
    int j=0;
    for(int i=j; i<n; i++){
        ans += (st*(i-j));
    }
    j=n/2;
    for(int i=j; i<n; i++){
        ans += (mid*(i-j));
    }
    for(int i=j; i>=0; i--){
        ans += (mid*(j-i));
    }

    long double an = (long double)ans/n;
    an += sum;
    cout<<an<<"\n";
}

