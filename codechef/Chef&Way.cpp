#include<bits/stdc++.h>

using namespace std;
int k;
int mod = 1000000009;
int prod(int n, int a[]){
    int min_prod = mod;
    for(int i=1; i<=k && n-i>=1; i++){
        min_prod = min(min_prod,(a[n-1]%mod*prod(n-i,a)%mod)%mod);
    }
    if(n<=1) return a[n-1];
    else return min_prod;
}

int main(){
    int t=1; //cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        cout<<prod(n,a)<<"\n";
    }
}