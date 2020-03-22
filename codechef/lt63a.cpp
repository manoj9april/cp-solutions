#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;
int a[lmt];
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        int ans=INT_MAX;
        for(int i=1; i<n; i++){
            ans  = min(ans,a[i]-a[i-1]);
        }
        cout<<ans<<"\n";
    }
}

