#include<bits/stdc++.h>

using  namespace std;

int dp[2001][2001];

int main(){
    int n,m;
    cin>>n>>m;

    int wt[26];

    for(int i=0; i<26; i++){
        cin>>wt[i];
    }

    string a,b;
    cin>>a>>b;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1] + wt[a[i-1]-'a'];
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    cout<<dp[n][m]<<"\n";
}