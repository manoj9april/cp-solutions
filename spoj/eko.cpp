#include<bits/stdc++.h>

using namespace std;
typedef long long ll;


int a[1000002];
ll n,wood;

bool check(ll ht){
    ll sum =0;
    for(int i=0; i<n; i++){
        if(a[i]>ht){
            sum += (ll)(a[i]-ht);
        }
    }
    return (sum>=wood);
}

int bs(int lo, int hi){
    int mid;
    while(lo<hi){
        mid =  lo + (hi-lo +1)/2;
        //cout<<mid<<" :mid\n";
        if(check(mid)) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main(){
    
    cin>>n>>wood;

    int h=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        h = max(h,a[i]);
    }
    
    int ans = bs(0,h);

    cout<<ans<<"\n";
}