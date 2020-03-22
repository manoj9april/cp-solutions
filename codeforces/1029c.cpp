#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int,int>

int const lmt = 3e5+3;
int st[lmt],en[lmt];

int main(){
    int n; cin>>n;
    int s,e;
    multiset<int> l,r;
    
    for(int i=0; i<n; i++){
        cin>>s>>e;
        st[i]=s; en[i]=e;
        l.insert(s);
        r.insert(e);
    }    
    if(n==1){
        cout<<0<<"\n";
    }

    ll ans=0;
    for(int i=0; i<n; i++){
        l.erase(l.find(st[i]));
        r.erase(r.find(en[i]));

        ll lt = *l.rbegin();
        ll rt = *r.begin();
        if(lt < rt){
            ans = max(ans,rt-lt);
        }

        l.insert(st[i]);
        r.insert(en[i]);
    }
    cout<<ans<<"\n";
}

