#include<bits/stdc++.h>

using namespace std;

int dp[6200][6200];
string s,r;

int lcs(int i,int j){
    if(i==0 || j==0){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    else if(s[i-1]==r[j-1]){
        return dp[i][j] = lcs(i-1,j-1) + 1;
    }else{
        return dp[i][j] = max(lcs(i-1,j) , lcs(i,j-1));
    }
}

int main(){
    int t,len; cin>>t;

    while(t--){
        memset(dp,-1,sizeof(dp));
        cin>>r;
        s=r;
        reverse(r.begin(),r.end());
        len = s.length();

        int res = lcs(len,len);

        cout<<len-res<<"\n";
    }
}