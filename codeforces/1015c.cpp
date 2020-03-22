#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll n,sum,s=0;
    cin>>n>>sum;
    ll a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
        s += a[i];
        a[i] -= b[i];
    }
    sort(a,a+n);
    int cnt=0;
    for(int i=n-1; s>sum && i>=0; i--){
        cnt++;
        s -= a[i];
    }
    cout<<(s>sum?-1:cnt)<<"\n";
}

