#include<bits/stdc++.h>

using namespace std ;

/*
int lcs(int i, int j){
    if(i==0) return dp[i][j]=j;
    else if(j==0) return dp[i][j]=i;
    else{
        if(a[i-1]==b[j-1]){

            return dp[i][j]=dp[i-1][j-1];
        }else{
            if(dp[i-1][j]<dp[i][j-1]){
                return dp[i][j]=dp[i-1][j];
            }else{
                return dp[i][j]=dp[i][j-1];
            }
        }
    }
}
*/
int main(){
    string  a,b;
    int dp[100][100];
    while(cin>>a>>b){
        int la = a.length();
        int lb = b.length();
        string track[la+1][lb+1];
        track[0][0]="";
        for(int i=0; i<=la; i++){
            for(int j=0; j<=lb; j++){
                if(i==0){
                    dp[i][j]=0;
                    track[i][j]="";
                }
                else if(j==0){
                    dp[i][j]=0;
                    track[i][j]="";
                }
                else{
                    if(a[i-1]==b[j-1]){
                        dp[i][j]=dp[i-1][j-1]+1;
                        track[i][j]= track[i-1][j-1] + a[i-1];
                    }else{
                        if(dp[i-1][j]>=dp[i][j-1]){
                            dp[i][j]=dp[i-1][j];
                            track[i][j]=track[i-1][j];
                        }else{
                            dp[i][j]=dp[i][j-1];
                            track[i][j]=track[i][j-1];
                        }
                    }
                }
            }
        }

        string common =track[la][lb];
        int lc= common.length();
        int p=0,q=0,c=0;
        while(p<la || q<lb){
            while(p<la && a[p]!=common[c]){
                cout<<a[p++];
            }while(q<lb && b[q]!=common[c]){
                cout<<b[q++];
            }

            while(c<lc && a[p]==common[c] && b[q]==common[c]){
                cout<<common[c++];
                p++; q++;
            }
        }
        cout<<"\n";
    }
}

