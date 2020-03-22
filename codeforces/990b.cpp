#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+5;
ll n,k;
ll a[lmt];
ll pre[lmt];
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>a[i];
    sort(a+1,a+n+1);
    int lo,hi;
    for(int i=1; i<=n; i++){
        hi = lower_bound(a,a+n+1,a[i])-a;
        lo = lower_bound(a,a+n+1,a[i]-k)-a;
        pre[lo]++;
        pre[hi]--;
    }
    ll cnt=0;
    for(int i=1; i<=n; i++){
        pre[i] += pre[i-1];
        if(pre[i]==0)cnt++;
    }
    cout<<cnt<<"\n";
}