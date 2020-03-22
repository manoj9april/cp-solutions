#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt = 1e5+4;
ll n,B;
int p[lmt],m[lmt];

bool check(ll prod){
    ll cost=0;
    for(int i=1; i<=n; i++){
        if(p[i]<prod){
            cost += 1LL*(prod-p[i])*m[i];

            if(cost>B || cost<0) return false;
        }
    }

    return cost<=B;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>B;
        ll hi=1e13+7,lo=INT_MAX;
        for(int i=1; i<=n; i++){
            cin>>p[i]>>m[i];
            lo = min(int(lo),p[i]);
        }

        ll mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check(mid)) lo=mid+1;
            else hi = mid-1;
        }

        cout<<hi<<"\n";
    }
}