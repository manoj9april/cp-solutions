#include<bits/stdc++.h>

using namespace std;

int dp[1000008];
bool done[1000008];

int k,l;

bool solve(int n){
    if(n==1 || n==k || n==l) return true;
    else if(done[n])return dp[n];
    else{
        done[n]=true;
        if(n>=l)
        return dp[n] = !(solve(n-1) && solve(n-k) && solve(n-l));
        else if(n>=k)
        return dp[n] = !(solve(n-1) && solve(n-k));
        else
        return dp[n] = !solve(n-1);
    }
}

int main(){
    int m;
    memset(done,false,sizeof(done));
    memset(dp,false,sizeof(dp));
    cin>>k>>l>>m;
    for(int i=0; i<m; i++){
        int ele; cin>>ele;
        cout<<(solve(ele)?"A":"B");
    }
}