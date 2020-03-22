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

int const lmt=1e5+5;

ll a[lmt];
map<ll, vpii> mpp;
set<ll> st;

ll be(ll n){
    ll a=2,ans=1;
    while(n){
        if(n&1) ans = (ans*a)%mod;
        n =n/2;
        a = (a*a)%mod;
    }
    return ans;
}

int main(){
    fast
    ll u,v,n,m,k;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    for(int i=0; i<m; i++){
        cin>>u>>v;
        ll x = a[u]^a[v];
        mpp[x].pb({u,v});
    }

    ll ans=0;
    for(auto it : mpp){

        ll sz=n+1;
        st.clear();
        for(auto p : it.second){
            u = p.f;  v = p.s;
            if(st.insert(u).s)sz--;
            if(st.insert(v).s)sz--;
        }

        ans = (ans + be(sz))%mod;
    }

    cout<<ans<<"\n";
}