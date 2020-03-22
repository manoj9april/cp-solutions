#include<bits/stdc++.h>

using namespace std;
typedef long long  ll;
typedef pair<int, int> PII;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define start                  first
#define end                    second

int dp[101][21][101];

int main(){
    int m,s;
    cin>>m>>s;
    while(m && s){
        PII girl[m+1];
        girl[0].start=girl[0].end=0;
        for(int i=1; i<=m; i++){
            cin>>girl[i].start>>girl[i].end;
        }

        memset(dp, 0 , sizeof dp);
        for(int i=0; i<=s; i++){
            for(int j=0; j<=m; j++){
                for(int g=girl[j].start; g<=girl[j].end; g++){
                    if(j==0 && i==0){
                        dp[i][j][g]=1;
                    }
                    else if(j==0){
                        dp[i][j][g]=0;
                    }
                    else
                        for(int gl=girl[j-1].start; gl<=i-g && gl<=girl[j-1].end; gl++)
                            dp[i][j][g] += dp[i-g][j-1][gl];
                }
            }
        }

        int ans =0;
        for(int i=girl[m].start; i<=girl[m].end; i++){
            ans += dp[s][m][i];
        }
        cout<<ans<<"\n";
        cin>>m>>s;
    }
}