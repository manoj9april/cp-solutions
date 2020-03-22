#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e9;
int main(){
    long long n,k,ans;

    cin>>n>>k;

    int a[n];

    for(int i=0; i<n; i++) cin>>a[i];

    sort(a,a+n);

    ans = a[k-1];
    if(k<n && a[k]==ans) ans=-1;
    if(k==0){
        ans = a[0]-1;
        if(ans <1) ans=-1;
    }
    cout<<ans<<"\n";
}