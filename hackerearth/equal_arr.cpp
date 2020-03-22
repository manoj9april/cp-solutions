#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e5+6;
ll a[lmt];

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            a[i] += a[i-1]; 
        }
        ll ans = 1e14;

        for(int i=1; i<n; i++){
            if(a[n]>=2*a[i])
            ans = min(ans,a[n]-2*a[i]);
        }

        cout<<(ans==1e14?-1:ans)<<"\n";
    }
}