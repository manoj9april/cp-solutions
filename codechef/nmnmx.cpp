#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll m = 1e9+7;
int const lmt = 5001;
ll nck[lmt][lmt];
ll a[lmt];
void pre(){
    for(int i=0; i<lmt; i++){
        for(int j=0; j<=i; j++){
            //if(j>i)nck[i][j]=0;
            if(j==i || j==0) nck[i][j] = 1;
            else nck[i][j]=(nck[i-1][j] + nck[i-1][j-1])%(m-1);
        }
    }
}
ll be(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1)ans = (ans*a)%m;
        a = (a*a)%m;
        n >>= 1;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    pre();
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        ll ans=1;
        for(int i=0; i<n; i++){
            ll pw = (nck[n-1][k-1] -(nck[i][k-1] + nck[n-1-i][k-1]));
            pw = (pw+m-1)%(m-1);
            ans = (ans*be(a[i],pw))%m;
        }

        cout<<ans<<"\n";
    }
}

