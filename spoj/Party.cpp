#include<bits/stdc++.h>

using namespace std;

int dp[502][101];

int main(){

    int mbud,n; cin>>mbud>>n;
    
    while(mbud!=0 && n!=0){
        int cost[n+1],fun[n+1];
    
        for(int i=1; i<=n; i++){
            cin>>cost[i]>>fun[i];
        }
    
        for(int i=0; i<=mbud; i++){
            for(int j=0; j<=n; j++ ){
                if(i<5 || j==0) dp[i][j] = 0;
                else if(fun[j]<1) dp[i][j]= dp[i][j-1];
                else{
                    dp[i][j] = max(fun[j] + dp[i-cost[i]][j-1], dp[i][j-1]);
                }
            }
        }
        cout<<dp[mbud][n];
        cin>>mbud>>n;

    }

}