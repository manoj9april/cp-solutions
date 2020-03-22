#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 1001;

int main(){
    freopen("ab.in","r",stdin);
    freopen("sample.out","w",stdout);
    ll t; cin>>t;
    for(ll tt=1; tt<=t; tt++){
        //
        ll n,o,d;
        cin>>n>>o>>d;
        ll x[n];
        ll a,b,c,m,lt; 
        cin>>x[0]>>x[1]>>a>>b>>c>>m>>lt;
        lt=0;
        for(ll i=2; i<n; i++){
            x[i] = (x[i-1]*a + x[i-2]*b +c)%m;
        }
        ll s[n];
        for(ll i=0; i<n; i++){
            s[i] = x[i]+lt;
        }
        ll l=0,r=0;
        ll odd=0,sm=0,ans=-1;
        for(r=0; r<n; r++){
            sm += s[r];
            odd += (s[r]%2);
            while(odd>o || sm>d){
                sm -= s[l];
                odd -= s[l]%2;
                l++;
            }
            if(sm>ans && sm<= d && odd<=o){
                ans=sm;
            }
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        if(ans==-1){
            cout<<"IMPOSSIBLE";
        }else cout<<ans;
        //
        cout<<"\n";
    }
}
