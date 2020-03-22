#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = (ll) 2e3 + 10 ;
const int INF = (ll) 1e9 ;
const int MOD = (ll) 1e9 + 7 ;
const int CHR = 97 ;
#define __Sync ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
#define __File freopen ( "input.txt" , "r" , stdin ) ; freopen ( "output.txt" , "w" , stdout ) ;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

int const lmt = 2e5+4;
int fre[lmt];
ll mod=1e9+7;

ll be(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1) ans = (ans*a)%mod;
        a = (a*a)%mod;
        n >>= 1;
    }
    return ans;
}
int main(){
    //cout<<be(1262197956167%mod,18)<<"\n";
    int n;cin>>n;
    int a=1;
    ll no=1;
    for(int i=0; i<n; i++){
        cin>>a;
        no = (no*a)%mod;
        fre[a]++;
    }
    //cout<<no<<endl;
    ll m = 1;
    for(int i=2; i<lmt; i++){
        m *= (fre[i]+1);
    }
    bool rt=false;
    if(m%2==1)rt=true;
    m >>= 1;

    ll ans = be(no%mod,m);
    if(rt)ans *= ((ll)sqrt(no)%mod);
    //cout<<no<<" "<<m<<"\n";
    cout<<(ans%mod)<<"\n";

    
}
//1262197956167