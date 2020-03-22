#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

int main(){
    int t; cin>>t;
    while(t--){
        ll  n,sum;
        cin>>n>>sum;
        int a[n+1];
        bool dp[sum+1][n+1];
        a[0]=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        for(int i=0; i<=sum; i++){
            for(int j=0; j<=n; j++){
                if(i==0) dp[i][j]=true;
                else if(j==0) dp[i][j]=false;
                else{
                    dp[i][j] = dp[i][j-1];
                    if(i>= a[j]){
                        dp[i][j] |= dp[i-a[j]][j-1];
                    }
                }
            }
        }

        bool ans=false;
        for(int j=0; j<=n; j++){
            ans |= dp[sum][j];
        }

        cout<<(ans?"Yes\n":"No\n");
    }
}



