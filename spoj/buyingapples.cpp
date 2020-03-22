#include<bits/stdc++.h>

using namespace std;

int n,k;
int price[101];
int dp[101][101];
int nop[101][101];
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;

        for(int i=1; i<=k; i++){
            cin>>price[i];
        }
        memset(nop,0,sizeof nop);
        memset(dp, 100000000, sizeof(dp));
        cout<<endl;
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                cout<<(dp[i][j]==100000000?-1:dp[i][j])<<" ";
            }cout<<endl;
        }
        for(int i=0; i<=k; i++){
            for(int j=0; j<=i; j++){
                if(i==0) {dp[i][j]=0;continue;}
                else if(j==0) { dp[i][j]=100000000; continue;}
                if( price[j]!=-1 && (price[j]+dp[i-j][j] <= dp[i][j-1]) && nop[i-j][j]<n){
                    dp[i][j] = price[j]+dp[i-j][j];
                    if(price[j]+dp[i-j][j] == dp[i][j-1]){
                        nop[i][j] = min(nop[i-j][j] + 1,nop[i][j-1]);
                    }
                    else nop[i][j] = nop[i-j][j] + 1;
                }else{
                    dp[i][j]=dp[i][j-1];
                    nop[i][j]=nop[i][j-1];
                }
            }
        }
        
        
        /*for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                cout<<nop[i][j]<<" ";
            }cout<<endl;
        }

        cout<<(dp[k][k]==100000000?-1:dp[k][k])<<endl;*/
    }
}