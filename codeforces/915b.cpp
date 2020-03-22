#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+7;

int main(){
    ll n,pos,l,r;
    cin>>n>>pos>>l>>r;
    ll ans=0;
    if(l>1 && r<n){
        ans = min(abs(pos-l),abs(pos-r))+(r-l)+2;
    }else if(l>1){
        ans = abs(pos-l)+1;
    }else if(r<n){
        ans = abs(pos-r)+1;
    }
    cout<<ans<<"\n";

}