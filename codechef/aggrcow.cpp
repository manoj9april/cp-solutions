# include<bits/stdc++.h>

typedef long long  ll;

#define mp                   make_pair

using namespace std;

ll n,cows; 
bool filled[100005];
queue< pair< ll,ll > >  q;
void solve(ll a,ll b){
    ll c = (a+b)/2;
    filled[c] = true;
    cows--;
    q.insert(mp(c,b));
    q.insert(mp(a,c));
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>cows;
        ll stall[n];
        for(int i=0; i<n; i++){
            cin>>stall[i];
        }
        sort(stall,stall+n);
        memset(filled,false,sizeof(filled));

        pair<ll,ll> pll;
        ll a=stall[0],b=stall[n-1]; 
        q.insert(mp(a,b))
        while(cows){
            pll = q.front(); q.pop();
            a = pll.first;
            b = pll.second;
            solve(a,b);
        }
        
    }
}