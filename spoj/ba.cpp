#include<bits/stdc++.h>
 
using namespace std;
 
int n,k;
int price[101];
int dp[101][101];
int nop[101][101];


int solve(int k, int j, int n){
	if(n<=0) return dp[k][j]=100000001;
	if(k=0) return dp[k][j]=0;
	if(j==0) return dp[k][j]=100000001;
	if(dp[k][j]!=100000000) return dp[k][j];
	else{
		if(price[j]!=-1 && k>=j)dp[k][j]=min(price[j]+solve(k-j,j,n-1) , solve(k,j-1,n));
		else dp[k][j]=solve(k,j-1,n);
		//cout<<dp[k][j]<<endl;
		return dp[k][j];
	}
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
 
        for(int i=1; i<=k; i++){
            cin>>price[i];
        }
        memset(nop,0,sizeof nop);
       // memset(dp, 100000000, sizeof(dp));
        //cout<<endl;
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                dp[i][j]=100000000;
            }
        }
        
        dp[k][k]=solve(k,k,n);
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                cout<<((dp[k][k]==100000001) ?-1:((dp[k][k]==100000000) ?-3:dp[k][k]))<<" ";
            }cout<<endl;
        }
        cout<<((dp[k][k]==100000001) ?-1:((dp[k][k]==100000000) ?-3:dp[k][k]))<<endl;
    }
}