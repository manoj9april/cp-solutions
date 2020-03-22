#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
ll n,k,m,a,cnt;
ll arr[21][21];
ll dp[21][21];
ll back(int i, int j){
    if(i==n-1 && j==m-1){
        a = a^(arr[i][j]);
        if(a==k)cnt++;
        a = a^(arr[i][j]);
        return cnt;
    }
    if(dp[i][j]!=-1)
    a = a^(arr[i][j]);
    if(i+1<n)back(i+1,j);
    if(j+1<m)back(i,j+1);
    a = a^(arr[i][j]);
}
int main(){
    cin>>n>>m>>k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>arr[i][j];
            dp[i][j]=-1;
        }
    }
    back(0,0);
    cout<<cnt<<"\n";
}

