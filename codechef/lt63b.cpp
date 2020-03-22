#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 5e5+6;
ll n,m,x;
set<ll> s,t;

int main(){
    cin>>n>>m>>x;
    ll ele;
    for(ll i=0; i<n; i++){
        cin>>ele;
        s.insert(ele);
    }  
    for(ll i=0; i<m; i++){
        cin>>ele;
        t.insert(ele);
    }
    auto its = s.end(),itt = t.end(); its--; itt--;
    ll ns=*its, nt= *itt,dc;
    
    while(ns>=x && nt>=x){
        s.erase(its);
        t.erase(itt);
        dc = min(ns/x , nt/x);
        s.insert(ns-x*dc);
        t.insert(nt-x*dc);
        its = s.end(); itt = t.end(); its--; itt--;
        ns=*its, nt= *itt;
    }
    
    ll ans = (ns+nt)-((*s.begin()) + (*t.begin()));
    ll prev = LLONG_MAX;
    while(prev>ans){
        prev = ans;
        s.erase(its);
        t.erase(itt);
        s.insert(ns-x);
        t.insert(nt-x);
        its = s.end(); itt = t.end(); its--; itt--;
        ns=*its, nt= *itt;
        ans = (ns+nt)-((*s.begin()) + (*t.begin()));
    }
    cout<<prev<<"\n";
}

