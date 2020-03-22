#include<bits/stdc++.h>

using namespace std;

int dp[11][1001][1001];

int  main(){
    int n,m,K;
    cin>>n>>m>>K;

    string s1,s2;
    cin>>s1>>s2;

    for(int k=0; k<=K; k++){
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(k==0) dp[k][i][j]=0;
                /*else if(j==0){
                    if(i>=k) dp[k][i][j]=0;
                    else dp[k][i][j] = -(n+m);
                }
                else if(i==0){
                    if(j>=k) dp[k][i][j]=0;
                    else dp[k][i][j] = -(n+m);
                }*/
                else if(i==0 || j==0){
                    dp[k][i][j]= -(n+m);
                }
                else{
                    if(s1[i-1]==s2[j-1]){
                        if(i-2>=0 && j-2>=0 && s1[i-2]==s2[j-2]){
                            dp[k][i][j]= 1+max(dp[k-1][i-1][j-1],dp[k][i-1][j-1]);
                        }else{
                            dp[k][i][j]= max(1+dp[k-1][i-1][j-1],dp[k][i-1][j-1]);
                        }
                    }else{
                        dp[k][i][j]= max(dp[k][i][j-1],dp[k][i-1][j]);
                    }
                }
                
            }
        }
    }

    cout<<dp[K][n][m]<<"\n";

}