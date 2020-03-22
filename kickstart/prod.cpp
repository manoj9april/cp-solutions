#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;
ll a[lmt];
int main(){
    freopen("samplec.in","r",stdin);
    freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        ll n;
        cin>>n;
        unordered_map<ll,ll> occ;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0; i<n; i++){
            occ[a[i]]++;
        }
        ll ans=0;
        for(int i=0; i<n; i++){
            occ[a[i]]--;
            for(int j=i+1; j<n; j++){
                occ[a[j]]--;
                if(a[i]==0 && a[j]==0){
                    ll k = n-1-j;
                    ans += k; continue;
                }
                ll pro = a[i]*a[j];
                ans += occ[pro];
                
            }
            for(int j=i+1; j<n; j++) occ[a[j]]++;
        }
        //
        cout<<"Case #"<<tt<<": ";
        //  
        cout<<ans<<"\n";
        //
        cout<<"\n";
    }
}
