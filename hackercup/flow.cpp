#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
/*
l = 0
r = 1
u = 2
d = 3
*/
ll mod = 1e9+7;
string a[3];
ll dp[3][lmt][4];
int vis[3][lmt];
int n;
bool ok(int i, int j){
    if(i>=0 && i<3 && j>=0 && j<n)return true;
    return false;
}
ll call(int i, int j, int dr){
    if(!ok(i,j) || a[i][j]=='#' || vis[i][j]) return 0;
    if(i==2 && j==n-1){
        if(dr!=2)return 0;
        else return 1;
    }
    if(dp[i][j][dr]!=-1)return dp[i][j][dr];
    vis[i][j]=1;
    if(dr==0 || dr==1){
        dp[i][j][dr]=(call(i-1,j,3))%mod + (call(i+1,j,2))%mod;
        dp[i][j][dr] %= mod; 
    }else{
        dp[i][j][dr]=(call(i,j-1,1))%mod + (call(i,j+1,0))%mod;
        dp[i][j][dr] %= mod; 
    }
    vis[i][j]=0;
    return dp[i][j][dr];
}
int main(){
    freopen("sample.in","r",stdin);
    //freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        int n; cin>>n;
        for(int i=0; i<3; i++){
            cin>>a[i];
            cout<<a[i]<<"\n";
        }
        memset(dp,-1,sizeof dp);
        memset(vis, 0, sizeof vis);
        cout<<call(0,0,0)<<"\n";
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<dp[0][0][0]<<"\n";
        
        //
        cout<<"\n";
    }
}
