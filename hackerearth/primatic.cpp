#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e4+6;
vector<int> sol;


int dp[lmt];

void pre(){
    vector<bool> pr(lmt,true);

    for(int i=2; i<lmt; i++){
        dp[i]=lmt;
        if(pr[i]){
            sol.push_back(i);
            for(int j=i*i; j<lmt; j+=i){
                pr[j]=false;
            }
        }
    }
    int len = sol.size();
    for(int i=0; i<len; i++){
        ll a = 1LL*pow(sol[i],sol[i]);
        if(a>lmt)break;
        sol.push_back(a);
    }
    sort(sol.begin(),sol.end());
}

int main(){
    pre();
    int len = sol.size();
    dp[0]=0;dp[1]=lmt;
    for(int i=0; i<len; i++){
        for(int j=0; j<lmt; j++){
            if(j>=sol[i]) dp[j] = min(dp[j],1+dp[j-sol[i]]); 
        }
    }
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<dp[n]<<"\n";
    }
    
}