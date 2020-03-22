#include <bits/stdc++.h>

using namespace std;

int cost[105];
int fun[105];

int cosst, ffun;
int dp[102][505];

int main()
{
    int bud, n;
    cin >> bud >> n;
    while (bud && n)
    {
        int W=bud;
        memset(dp, -1, sizeof(dp));
        cosst = 0;
        //cout<<"hhhh\n";
        for (int i = 1; i <= n; i++)
        {
            cin >> cost[i] >> fun[i];
            
        }
        //cout<<"hhhh\n";

        for(int i=0; i<=n; i++){
            for(int j=0; j<=W; j++){
                if(i==0 || j==0){
                    dp[i][j] =0;
                }
                else{
                    if(cost[i]<=j)
                        dp[i][j] = max(dp[i-1][j] , fun[i] + dp[i-1][j-cost[i]]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        for(int i=0; i<=W; i++){
            if(dp[n][i] == dp[n][W]){
                cosst = i;
                break;
            }
        }

        cout<<cosst<<" "<<dp[n][W]<<"\n";
        cin >> bud >> n;
    }
}