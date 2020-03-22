#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = (ll) 2e3 + 10 ;
const int INF = (ll) 1e9 ;
const int MOD = (ll) 1e9 + 7 ;
const int CHR = 97 ;
#define __sync ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
#define __File freopen ( "input.txt" , "r" , stdin ) ; freopen ( "output.txt" , "w" , stdout ) ;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

ll dp[2005][2005];

int main(){
    __sync
    
    int n,k; cin>>n>>k;

    memset(dp,0, sizeof dp);
    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(i==1) dp[i][j]=1;
            else{
                for(int r=j; r<=n; r+=j){
                    dp[i][r] = (dp[i][r] + dp[i-1][j]) % MOD; 
                }
            }
        }
    }
    ll ans=0;
    for(int i=1; i<=n; i++){
        ans = (ans + dp[k][i]) % MOD;
    }

    cout<<ans<<"\n";
}