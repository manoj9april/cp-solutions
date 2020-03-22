#include<bits/stdc++.h>

using namespace std;

int dp[3][1001][1001];


int solve(int status, int h, int a){
    if(h<=0 || a<=0)return 0;
    if(dp[status][h][a] != -1) return dp[status][h][a];
    if(status == 0){
        //done[status][h][a] = true;
        return dp[status][h][a] = max(solve(1,h-5, a-10),solve(2,h-20, a+5)) +1;
    }else if(status==1){
        //done[status][h][a] = true;
        return dp[status][h][a] = solve(0,h+3, a+2) +1;
    }else{
        //done[status][h][a] = true;
        return dp[status][h][a] = solve(0,h+3, a+2) +1;
    }
}

int main(){
    memset(dp,-1, sizeof dp);
    int t; cin>>t;
    while(t--){
        int h,a;
        cin>>h>>a;

        int ans = solve(0,h+3, a+2);
        cout<<ans<<endl;
    }
}