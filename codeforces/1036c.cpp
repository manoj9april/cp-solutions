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

ll dp[70][5];

ll solve(int n, int nz){
    if(nz<=1) return 0;
    if(dp[n][nz]!=-1) return dp[n][nz];
    ll ans=0;
    int it=3,nzz=nz-1;
    for(int i=n-1; it && nzz && i>=nz; i--){
        ans += solve(i,nzz);
        it--; nzz--;
    }
    return dp[n][nz]=ans;
}

string a,b;

ll fun(ll n){
    if(n<=0) return 0;
    a = to_string(n);
    int len = a.length();
    int nz=0;
    ll ans=0;
    for(int i=1; i<len; i++){
        if(a[i-1]!='0') nz++;
        ans += solve(len-i,3-nz);
    }
    return ans;
}

int main(){
    fast
    ll t; cin>>t;
    ll l,r;
    memset(dp,-1,sizeof dp);
    while(t--){
        cin>>l>>r;
        cout<< fun(r) - fun(l-1) <<"\n";
    }
}