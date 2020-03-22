#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int const lmt=15;
ll a[lmt][5],b[lmt][5],dp[lmt][5];
ll R;

void det(int r){
    for(int i=r; i>=max(r-4,0); i--){
        for(int j=0; j<5; j++){
            if(a[i][j]==-1){
                a[i][j]=0;
                b[i][j]=-1;
            }
        }
    }
}

void udet(int r){
    for(int i=r; i>=max(r-4,0); i--){
        for(int j=0; j<5; j++){
            if(b[i][j]==-1){
                a[i][j]=b[i][j];
                b[i][j]=0;
            }
        }
    }
}
ll ga=-1;

void solve(){
    memset(dp,-1,sizeof dp);
    for(int i=0; i<=R; i++){
        for(int j=0; j<5; j++){
            ll &ans = dp[i][j];
            if(a[i][j]==2)ans=0;
            else{
                if(i==0)ans = a[i][j];
                else  ans = a[i][j] + max(dp[i-1][max(0,j-1)],
                            max(dp[i-1][j],dp[i-1][min(4,j+1)])) ;
            }
        }
    }
    ga = max(ga,dp[R][2]);
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif

    int T; cin>>T;
    
    for(int t=1; t<=T; t++){
        cin>>R;
        ga=-1;
        memset(a,0,sizeof a);
        for(int i=0; i<R; i++){
            for(int j=0; j<5; j++){
                cin>>a[i][j];
                if(a[i][j]==2)a[i][j]=-1;
                else if(a[i][j]==0)a[i][j]=2;
            }
        }
        solve();
        for(int i=R-1; i>=4; i--){
            det(i);
            solve();
            udet(i);
        }

        cout<<ga<<"\n";
    }
}