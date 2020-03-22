#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int cost[n+1];
        for(int i=1; i<=n; i++){
            cin>>cost[i];
        }

        ll dp[n+9];
        memset(dp,0,sizeof dp);
        dp[n]=cost[n];
        for(int i=n-1; i>=1; i--){
            if(i>=n-2){
                dp[i] = cost[i] + dp[i+1];
                continue;
            }

            dp[i] = cost[i] + dp[i+2];
            dp[i] = max(dp[i],cost[i]+cost[i+1]+ dp[i+4]);
            dp[i] = max(dp[i],cost[i]+cost[i+1]+cost[i+2]+ dp[i+6]);

        }

        cout<<dp[1]<<"\n";
    }
}