# include<bits/stdc++.h>

typedef long long  ll;

#define mp                   make_pair

using namespace std;

map<int, ll> mii;

ll solve(ll n){
    map <int, ll> :: iterator it;it=mii.find(n);
    if(it!=mii.end()) return it->second;
    ll a=solve(n/2) ,b=solve(n/2) ,c=solve(n/2) ;
    mii.insert(pair <int, ll> (n/2, a));//a[n/2] = solve(n/2);
    mii.insert( pair <int, ll> (n/3, b));//a[n/3] = solve(n/3);
    mii.insert( pair <int, ll> (n/4, c));//a[n/4] = solve(n/4);

    return max(n,(a+b+c));
}

int main(){
    long long n,sum=0;
    
    while(cin>>n){
        mii.clear();
        cout<<solve(n)<<"\n";
    }
}