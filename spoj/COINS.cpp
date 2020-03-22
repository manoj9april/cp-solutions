# include<bits/stdc++.h>

typedef long long  ll;

using namespace std;
map<int, ll> a;
ll solve(ll n){
    if(n==0) return 0;
    if(a[n]!=0) return a[n];

    a[n/2] = solve(n/2);
    a[n/3] = solve(n/3);
    a[n/4] = solve(n/4);

    return max(n,(a[n/2]+a[n/3]+a[n/4]));
}

int main(){
    long long n,sum=0;
    while(cin>>n){
        cout<<solve(n)<<"\n";
    }
}