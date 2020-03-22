#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;

int main(){
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        ll n,q; cin>>n>>q;
        ll x1,x2,a1,b1,c1,m1; cin>>x1>>x2>>a1>>b1>>c1>>m1;
        ll y1,y2,a2,b2,c2,m2; cin>>y1>>y2>>a2>>b2>>c2>>m2;
        ll z1,z2,a3,b3,c3,m3; cin>>z1>>z2>>a3>>b3>>c3>>m3;
        ll l,r;
        vector<pair<ll,int> > v;
        v.push_back({min(x1,y1),0});
        v.push_back({max(x1,y1),1});
        v.push_back({min(x2,y2),0});
        v.push_back({max(x2,y2),1});
        for(ll i=3; i<=n; i++){
            x2 = (a1*x1 + b1*x2 + c1)%m1;
            y2 = (a2*y1 + b2*y2 + c2)%m2;
            z2 = (a3*z1 + b3*z2 + c3)%m3;

            v.push_back({min(x2,y2),0});
            v.push_back({max(x2,y2),1});
        }
        for(int i=0; i<v.size(); i++){
            if(v[i].second==0){
                val++;
            }else{

            }
        }
        //
        cout<<"Case #"<<tt<<": ";
        //

        //
        cout<<"\n";
    }
}
