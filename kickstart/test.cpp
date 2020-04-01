#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;
ll n,k;
ll a[lmt];

bool check(ll mid){
    ll val = 0;
    for(int i=1; i<n; i++){
        ll diff = a[i]-a[i-1];
        val += (diff+mid-1)/mid - 1;
    }
    return (val <= k);
}

int main(){
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        
        cin>>n>>k;
        for(int i=0; i<n; i++) cin>>a[i];

        ll lo=1, hi = 1e9+5,mid;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(check(mid)) hi = mid-1;
            else lo = mid+1;
        }

        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<lo;
        //
        cout<<"\n";
    }
}
