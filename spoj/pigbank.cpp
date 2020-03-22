#include <bits/stdc++.h>

using namespace std;




int main(){
    int t; cin>>t;

    while(t--){
        int a,b; cin >>a>>b;
        int w = b-a;

        int n; cin>>n;
        int value[n+1],wt[n+1];
        int dp[n+1][w+1];
        for(int i=1; i<=n; i++){
            cin>>value[i]>>wt[n];
        }
        for(int i=0; i<=n; i++){
            for(int j=0; j<=w; j++){
                if(i==0  ||  j==0){
                    dp[i][j]=0;
                }
                else{
                    if(wt[i]<=j){
                        if( dp[i-1][j]==0){
                            dp[i][j]=value[i] + dp[i-1][j-wt[i]];
                        }else
                            dp[i][j]=min(value[i] + dp[i-1][j-wt[i]] , dp[i-1][j]);
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }

        cout<<dp[n][w]<<"\n";
    }
}