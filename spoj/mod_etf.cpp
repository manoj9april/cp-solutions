#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int lmt = 1e7+1;
const int sz = 1e5+1;
ll phi[sz];   //  phi[0]==>phi[a]   phi[i]==>phi[i+a]
bool prime[lmt];

vector<ll>  pr;
void cal_etf(ll a, ll b){
    
    for(ll i=a; i<=b; i++){  
        phi[i-a]=i;
    }
    bool sprime[b-a+1];
    memset(prime, true, sizeof prime);
    memset(sprime, true, sizeof sprime);
    for(ll i=2; i*i<lmt; i++){
        if(prime[i]){
            for(ll j=i*i; j<lmt; j++){
                prime[j]=false;
            }
        }
    }

    for(ll i=2; i<lmt; i++){
        if(prime[i]){
            pr.push_back(i);
        }
    }
    ll len = pr.size();
    for(ll i=0; i<len; i++){
        ll prm = pr[i];
        ll j = prm*ceil(1.0*a/prm);
        for(; j<=b; j+=prm){
            sprime[j-a] = false;
        }
    }
    for(ll j=a; j<=b; j++){
        if(b<lmt)break;
        if(j>lmt){
            if(sprime[j-a]){
                pr.push_back(j);
            }
        }
    }
    len = pr.size();

    for(ll i=0; i<len; i++){
        ll prm = pr[i];
        ll j = prm*ceil(1.0*a/prm);
        for(; j<=b; j+=prm){
            phi[j-a] -= phi[j-a]/prm;
        }
    }
}

int main(){
    ll a,b;
    cin>>a>>b;
    cal_etf(a,b);
    for(ll i=a; i<=b; i++){
        cout<<phi[i-a]<<"\n";
    }
}   