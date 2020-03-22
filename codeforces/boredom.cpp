#include <bits/stdc++.h>

using namespace std;

#define pb   push_back

int main(){
    int n; cin>>n;

    int a[n];
    int f[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        f[i]=0;
    }

    sort(a,a+n);
    vector<int>  v;

    v.pb(a[0]);
    f[0]=1;
    for(int i=1,j=0; i<n; i++){
        if(a[i]==a[i-1]) f[j]++;
        else{
            v.pb(a[i]);
            f[++j]=1;
        }
    }

    int len = v.size();

    long long dp[len];
    dp[0] = 1LL*v[0]*f[0];
    if(len>0){
        if(v[1]!=1+v[1-1]){
            dp[1] = dp[1-1] + 1LL*v[1]*f[1] ;
        }else{
            dp[1] = max(dp[0], 1LL*v[1]*f[1]);
        }
    } 
    for(int i=2; i<len; i++){
        if(v[i]!=1+v[i-1]){
            dp[i] = dp[i-1] + 1LL*v[i]*f[i] ;
        }else{
            dp[i] = max(dp[i-1], dp[i-2] + 1LL*v[i]*f[i]);
        }
    }

    cout<<dp[len-1]<<"\n";
}



