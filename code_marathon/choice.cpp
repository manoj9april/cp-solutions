#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define scll(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

const double pi=acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

int const lmt=2*(1e6+3);


int fact[lmt];

ll be(ll x,ll n)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%MOD;
        x=(x*x)%MOD;
        n=n/2;
    }
    return result;
}

ll  modInv(ll n){
    return be(n,MOD-2);
}
void calFact(ll n){
    fact[0] = 1;
    for (ll i=1 ; i<=n; i++)
        fact[i] = (fact[i-1]*(i%MOD)) % MOD; //cout<<fact[i]<<"\n";}
        
}


ll nCrM(ll n, ll r)
{
    if (r == 0)
        return 1;

    return (fact[n]*modInv(fact[r])% MOD * modInv(fact[n - r])%MOD) %MOD;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1; //cin>>t;
    while(t--){
        
        ll n,x,k; cin>>n>>x>>k;
        
        calFact(n+x+1);
        ll sum =0;
        while(n--){
            sum += 1LL*(nCrM(x,k));
            //cout<<nCrM(x,k)<<"\n";
            sum %= MOD;
            x++;
        }
        //cout<<"5! "<<fact[5]<<"\n modInv(fact[3])"<<(fact[3])<<"\n mi(f2)"<<(fact[2])<<"\n";
        cout<<sum<<"\n";

    }
}