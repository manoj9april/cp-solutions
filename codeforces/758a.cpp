#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    int a[n],mx=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mx = max(mx,a[i]);
    }    
    ll ans=0;
    for(int i=0; i<n; i++){
        ans += 1ll*(mx-a[i]);
    }
    cout<<ans<<"\n";
}

