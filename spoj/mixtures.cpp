#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e2+3;
int const inf = 1e9+8;

int dp1[lmt][lmt];
int dp2[lmt][lmt];
int arr[lmt];

void solve(int i, int j){
    //if(j<i) return ;
    if(dp2[i][j]!=inf) return;
    if(i==j){
        dp1[i][i]=arr[i]%100;
        dp2[i][i]=0;
    }
    else{
        for(int k=i; k<j; k++){
            solve(i,k);
            solve(k+1,j);

            if(dp2[i][j] >= (dp2[i][k] + dp2[k+1][j] + dp1[i][k]*dp1[k+1][j])){
                dp2[i][j] = (dp2[i][k] + dp2[k+1][j] + dp1[i][k]*dp1[k+1][j]);
                dp1[i][j] = (dp1[i][k] + dp1[k+1][j])%100;
            }
        }
    }
}

int main(){
    int n;
    while(cin>>n){
        for(int i=0; i<n; i++){
            cin>>arr[i];
            for(int j=0; j<n; j++){
                dp2[i][j]=inf;
            }
        }

        //memset(dp2, inf, sizeof dp2);
        solve(0,n-1);

        cout<<dp2[0][n-1]<<"\n";
    }
}