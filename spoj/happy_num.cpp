#include<bits/stdc++.h>

using namespace std;
#define ll long long 

int check[1000];
int cnt=0;
int solve(ll n){
    cnt++;
    int ne=0,mod;
    while(n){
        mod = n%10;
        ne += mod*mod;
        n /= 10;
    }
    if(ne==1) return cnt;
    else if(check[ne]==1) return -1;
    
    check[ne]=1;
    return solve(ne);
}
int main(){
    ll n; cin>>n;

    cout<<solve(n)<<"\n";
}