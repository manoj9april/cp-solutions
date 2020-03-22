#include<bits/stdc++.h>

using namespace std;

int dp[20000009];

int solve(int n){
    if(n<=1)return 0;
    else if(dp[n]!=-1) return dp[n];
    int res=INT_MAX;
    if(n%3==0){
        res = min(res,solve(n/3));
    }
    if(n%2==0){
        res = min(res,solve(n/2));
    }
    res = min(res,solve(n-1));

    return dp[n]=res+1;
}

int main(){
    memset(dp,-1,sizeof dp);
    int t,r=1; cin>>t;
    while(t--){
        
        int n;cin>>n;
        int steps=0;
        steps = solve(n);
        cout<<"Case "<<r++<<": "<<steps<<endl;
    }
}