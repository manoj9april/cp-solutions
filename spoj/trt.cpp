#include<bits/stdc++.h>

typedef long long  ll;

using namespace std;

ll a[2001];
ll dp[2001][2001];

ll solve(int i,int j,int value){
    if(i==j){
        return a[i]*value;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    else{
        return dp[i][j] = max(a[i]*value + solve(i+1,j,value+1) , a[j]*value + solve(i,j-1,value+1));
    }
}

int main(){
    int t; cin>>t;
    memset(dp,-1,sizeof dp);
    for(int i=0; i<t; i++){
        cin>>a[i];
    }
    ll res = solve(0,t-1,1);
    cout<<res;
}