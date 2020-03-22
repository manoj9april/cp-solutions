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

ll cost[lmt],c[lmt],lt[lmt];

ll be(ll n){
    ll a=2,ans=1;
    while(n){
        if(n&1) ans = ans*a;

        n = n/2;
        a = a*a;
    }
    return ans;
}

int main(){
    fast
    ll n,l;
    cin>>n>>l;

    ll ctr=1;
    loop(i,n){
        cin>>cost[i];
    }
    c[0]=cost[0];
    for(int i=1; i<n; i++){
        c[i] = min(cost[i],2*c[i-1]);
    }
    ll ans=4e18+5;
    ll sum=0;
    for(ll i=n-1; i>=0; i--){
        ll need = l/(1<<i);
        sum += need*c[i];
        l %= (1<<i);
        ans = min(ans,sum + c[i]);
    }
    ans  = min(ans,sum);
    cout<<ans<<"\n";
}