#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll p;

string res="";
bool dp[8][101];
bool done[8][101];

int solve(ll n, ll s){
    if(s==0)  return true;
    else if(s<0) return false;
    if(n==0) return false;

    if(done[n][s]) return dp[n][s];
    if(p==0){

    }
    for(int i=1; i<=9; i++){
        if(p%i==0){
            ll ans = solve(n-1,s-i);
            if(i*ans == p){
                res = to_string(i) + res;
                return p;
            }
        }
    }

}

int main(){
    ll n,s;
    cin>>n>>s>>p;
}