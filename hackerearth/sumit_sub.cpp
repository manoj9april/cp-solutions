#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e5+6;

int a,dp;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ans=-(1e9+2),ans2=0;
        for(int i=1; i<=n; i++){
            cin>>a;
            dp = max(a,a+dp);
            ans = max(ans,dp);
            if(a>0)ans2 += a;
        }

        cout<<ans<<" "<<ans2<<"\n";
    }
}