#include <bits/stdc++.h>

using namespace std;
const int lmt=1000;
int dp[lmt][lmt];

int main(){
    int t=1; //cin>>t;
    while(t--){
        int len; cin>>len;
        string a,b;
        cin>>a;
        b=a;

        
        reverse(b.begin(),b.end());

        for(int i=0; i<=len; i++){
            for(int j=0; j<=len; j++){
                if(i==0)dp[i][j]=0;
                else if(j==0)dp[i][j]=0;
                else if(a[i-1]==b[j-1]){
                    dp[i][j]= 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }

        cout<<len-dp[len][len]<<endl;
    }
}