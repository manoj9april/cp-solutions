#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt = 2*1e6 + 8;
int const M = 1e9+7;

ll dp[lmt];


int main(){
    string s;
    cin>>s;

    int len = s.length();

    dp[0]=0;
    dp[1]=s[0]-'0';
    for(ll i=2; i<=len; i++){
        dp[i] = (dp[i-1] + (10*((dp[i-1]-dp[i-2])%M))%M + (i*(s[i-1]-'0'))%M  + M)%M;
    }

    cout<<dp[len]<<"\n";    
}