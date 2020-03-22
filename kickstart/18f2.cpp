#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>

int const lmt = 2e5+6;

int main(){
    freopen("sample.in","r",stdin);
    freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        ll n,m,l;
        cin>>n>>m;

        map<int,int> sp;
        vector<bool> occ(n+1,false);
        vector<pii> v;
        vector<int> a(m+1),b(m+1);

        for(int i=0; i<m; i++){
            cin>>a[i]>>b[i]>>l;
            if(l==0){
                sp[a[i]]++;
                sp[b[i]]++;
            }
            v.push_back({l,i});
        }
        ll ans=1;
        sort(v.begin(),v.end());
        int ind,aa,bb;
        for(int i=0; i<m; i++){
            ind = v[i].second;
            aa = a[ind]; bb = b[ind];

            if(occ[aa]==0 && occ[bb]==0) ans *= 2;
            else if(occ[aa]!=0 && sp[aa] && occ[bb]==0) ans *= 2;
            else if(occ[bb]!=0 && sp[bb] && occ[aa]==0) ans *= 2;

            occ[aa]=1;
            occ[bb]=1;
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<< ans<<"\n";
        //
        cout<<"\n";
    }
}
