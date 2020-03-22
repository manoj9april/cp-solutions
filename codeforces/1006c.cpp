#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
map<ll, int> mp;
int main(){
    int n; cin>>n;
    ll a[n];
    ll sum=0;
    mp[0]++;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+= a[i];
        mp[sum]++;
    }
    ll ans=0;
    ll ns=0;
    for(int i=n-1; i>=0; i--){
        mp[sum]--;
        sum -= a[i];
        ns += a[i];
        if(mp[ns]){
            ans = max(ans,ns);
        }
    }

    cout<<ans<<"\n";
}

