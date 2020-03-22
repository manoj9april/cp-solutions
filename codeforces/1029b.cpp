#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+7;
ll a[lmt];
int main(){
    ll n; cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    ll ans=1,len,cnt;
    for(int i=0; i<n; i++){
        cnt=1;
        while(i+1<n && 2*a[i]>=a[i+1]){i++;cnt++;}
        ans = max(cnt,ans);
    }
    cout<<ans<<"\n";
}

