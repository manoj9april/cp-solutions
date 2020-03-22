#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;

        int n1 = a.length();
        int n2 = b.length();//cout<<n1<<" "<<n2<<" ";
        int dp[n1+1][n2+1];
        //memset(dp, 0 , sizeof(dp));
        for(int i=0; i<=n1; i++){
            for(int j=0; j<=n2; j++){
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                else{
                    dp[i][j] = max(dp[i-1][j-1] ,max(dp[i-1][j] ,  dp[i][j-1]));
                }
            }
        }

        cout<<(dp[n1][n2])<<endl;
    }
}