#include<bits/stdc++.h>
typedef long long ll;

using namespace std;
ll n,c; 
bool bs(ll k, ll *x){
    ll dis=0,cnt=1;
    for(int i=1; i<n; i++){
        dis += x[i] - x[i-1];
        if(dis>=k){
            dis=0; cnt++;
        }
        if(cnt==c) return true;
    }
    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>c;
        ll x[n];
        for(int i=0; i<n; i++){
            cin>>x[i];
        }
        sort(x,x+n);
        ll lo=0, mid,hi=x[n-1],ans;

        while(lo<hi){
            mid = lo + (hi-lo+1)/2;
            
            if(bs(mid,x)){
                //if(mid==lo) break;
                lo = mid;
            }else{
                hi = mid-1;
            }
        }
        cout<<lo<<endl;
    }
}

