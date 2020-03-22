#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    int a[2*n];
    for(int i=0; i<2*n; i++){
        cin>>a[i];
    }
    sort(a,a+2*n);
    ll l,b=a[2*n-1]-a[0];
    ll ans = 1LL*(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    
    for(int i=n; i<2*n-1; i++){
        l = a[i]-a[i-n+1];
        ans = min(ans,l*b);
    }
    cout<<ans<<"\n";
}

