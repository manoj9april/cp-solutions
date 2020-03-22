#include<bits/stdc++.h>

using namespace std;

#define f first
#define s second

pair<int , char > dp[5002][5002];

int main(){
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        for(int i=0; i<=n; i++){
            for(int j=0; j<=m; j++){
                if(i==0 && j==0){
                    dp[i][j].f=0;
                    dp[i][j].s='2';
                }else if(i==0){
                    dp[i][j].f=dp[i][j-1].f + (s2[j-1]==dp[i][j-1].s? 0:1);
                    dp[i][j].s=s2[j-1];
                }else if(j==0){
                    dp[i][j].f=dp[i-1][j].f + (s1[i-1]==dp[i-1][j].s? 0:1);
                    dp[i][j].s=s1[i-1];
                }else{
                    dp[i][j].f=1000600;
                    if(s1[i-1]==dp[i-1][j].s){
                        if(dp[i][j].f>dp[i-1][j].f){
                            dp[i][j].f=dp[i-1][j].f;
                            dp[i][j].s=s1[i-1];
                        }
                    }else{
                        if(dp[i][j].f>dp[i-1][j].f+1){
                            dp[i][j].f=dp[i-1][j].f+1;
                            dp[i][j].s=s1[i-1];
                        }
                    }

                    if(s2[j-1]==dp[i][j-1].s){
                        if(dp[i][j].f>dp[i][j-1].f){
                            dp[i][j].f=dp[i][j-1].f;
                            dp[i][j].s=s2[j-1];
                        }
                    }else{
                        if(dp[i][j].f>dp[i][j-1].f){
                            dp[i][j].f=dp[i][j-1].f + 1;
                            dp[i][j].s=s2[j-1];
                        }
                    }
                }
            }
        }

        cout<<dp[n][m].f<<"\n";
    }
}

