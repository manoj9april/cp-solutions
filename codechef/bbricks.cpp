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
#define loop(i,n) rep(i,0,n-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define rloop(i,n) rev_rep(i,n-1,0,1)
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e3+5;
ll be(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1) ans = (ans*a)%mod;

        n = n/2;
        a = (a*a)%mod;

    }

    return ans;
}
ll inv(ll n){
    return be(n,mod-2);
}
int main(){
    fast
    int t; cin>>t;
    
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(k>n){
            cout<<"0\n";
            continue;
        }
        ll cur=1,ans = 0,a=n-k+1,b=k-1,nn,rr;
        for(ll i=1; i<=k;i++){
            //if(i>a || i-1 > b) break;
            rr = i;
            nn = a-rr+1;
            cur = (cur*2)%mod;
            cur = (1ll*(cur*nn)%mod*inv(rr))%mod;
            
            //dbg(nn);
            rr = i-1;
            nn = b-rr+1;
            if(rr) cur = (1ll*(cur*nn)%mod*inv(rr))%mod;

            //dbg(cur);
            ans = (ans+cur)%mod;
        }

        cout<< ans << "\n";
    }
}