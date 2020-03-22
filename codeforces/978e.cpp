#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
ll n,w;

int main(){
    cin>>n>>w;
    ll mn=0,mx=0,s=0,a;
    for(int i=0; i<n; i++){
        cin>>a;
        s += a;
        mn = min(mn,s);
        mx = max(mx,s);
    }
    if(mx-mn>w)cout<<"0\n";
    else cout<<(w+1-(mx-mn))<<"\n";
}