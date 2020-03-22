#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int a[n+2];
    int dp1[n+2]={0};
    int dp2[n+2]={0};
    
    a[0]=0;dp1[0];
    a[n+1]=INT_MAX; dp2[n+1]=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }

    for(int i=1; i<=n; i++){
        if(a[i]>a[i-1]){
            dp1[i] = dp1[i-1]+1;
        }else{
            dp1[i]=1;
        }
    }
    for(int i=n; i>=1; i--){
        if(a[i]<a[i+1]){
            dp2[i] = dp2[i+1]+1;
        }else{
            dp2[i]=1;
        }
    }

    int ans=0; 
    for(int i=1; i<=n; i++){
        if(a[i-1]+2<=a[i+1]){
            ans = max(ans, dp1[i-1]+dp2[i+1]+1);
        }else{
            ans = max(dp1[i-1]+1,max(dp2[i+1]+1, ans));
        }
    }

    cout<<ans<<"\n";
}