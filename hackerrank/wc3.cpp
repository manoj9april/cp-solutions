#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt=1e5+6;

ll n,m,k;


int main(){
    int t; cin>>t;

    while(t--){
        
        cin>>n>>m>>k;
        ll inv = 1;
        ll a=k,nn=m-2;
        while(nn){
            if(nn&1) inv = (inv*a)%m;

            a = (a*a)%m;
            nn = nn>>1;
        }
        multiset<int> st;
        //st.insert(k);
        ll pre=1;
        ll aa;
        ll ans=0;
        for(int i=0; i<n; i++){
            cin>>aa;
            pre = (pre*aa)%m;

            int cnt = st.count((pre*inv)%m);

            ans += cnt;
            cout<<i<<" ----"<<cnt<<"\n";
            st.insert((pre)%m);

        }

        cout<<ans<<"\n";
    }
}