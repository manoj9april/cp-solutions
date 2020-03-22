#include<bits/stdc++.h>

using namespace std;
#define ll long long

long long const M = 1e9 + 7;

int const lmt =1e6+3;

ll be(ll a, ll n){
    ll ans =1;
    while(n){
        if(n&1) ans = (ans*a)%M;

        a = (a*a)%M;
        n = n>>1;
    }
    return ans;
}

ll arr[lmt];
ll spec[lmt];

int main(){
    freopen("alarm_l.in","r",stdin);
    freopen("alarm_l.out","w",stdout);
    int t; cin>>t;
    int tt=1;

    while(t--){
        ll n,k,x,y,c,d,e1,e2,f;
        cin>>n>>k>>x>>y>>c>>d>>e1>>e2>>f;

        
        //cout<<"array : ";
        for(int i=1; i<=n; i++){
            arr[i] = (x+y)%f;
            //cout<<arr[i]<<" ";
            ll tx = (c*x + d*y + e1)%f;
            ll ty = (d*x + c*y + e2)%f;
            x = tx; y = ty;
        }
        //cout<<endl;
        spec[1]=k;

        for(int i=2; i<=n; i++){
            spec[i] = ((be(i,k+1)-1)*be(i-1,M-2)-1)%M;
            spec[i] = (spec[i]+spec[i-1])%M;
        }

        ll ans=0;

        for(int i=1; i<=n; i++){
            ll val = (arr[i]*(n+1-i))%M;
            val = (val*spec[i])%M;

            ans = (ans+val)%M;
        }

        cout<<"Case #"<<tt<<": "<<(ans%M)<<"\n";
        tt++;
    }
}