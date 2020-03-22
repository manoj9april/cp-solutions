#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll ans,k,a,b;
    cin>>k>>a>>b;
    ans = (a/k)+(b/k);
    if((a%k && !(b/k))|| (b%k && !(a/k)))ans=0;
    cout<<(ans==0?-1:ans)<<"\n";

}