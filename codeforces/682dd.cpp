#include<bits/stdc++.h>

using namespace std;

int dp[11][1001][1001][2];

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
                    dp[k][i][j][e]= -(n+m);
                }
                else{

                }
                
            }
        }
    }

    cout<<dp[K][n][m]<<"\n";

}