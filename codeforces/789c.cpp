#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int  main(){
    int n; cin>>n;
    ll a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<n; i++){
        b[i] = abs(a[i]-a[i-1]);
    }
    ll sum=0,best=max(b[n-1],b[n-2]);
    a[n-1]=b[n-1]; a[n-2]=b[n-2];
    for(int i=n-3; i>=1; i--){
        a[i] = max(b[i],b[i]-b[i+1]+a[i+2]);
        best = max(best, a[i]);
    }

    cout<<best<<"\n";
}