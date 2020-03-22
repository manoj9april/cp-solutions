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

int const lmt=1e5+5;
vector<int> adj[lmt];
ll cnt[lmt];
ll val[lmt];
ll k,ans;

void dfs(int p, ll x){
    x ^= val[p];
    ans += cnt[x^k];
    cnt[x]++;
    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        dfs(c,x);
    }
    cnt[x]--;
}

int main(){
    fast
    int t=1; //cin>>t;
    while(t--){
        int n;
        cin>>n>>k;
        for(int i=1; i<=n; i++)cin>>val[i];
        int x;
        for(int i=2; i<=n; i++){
            cin>>x;
            adj[x].push_back(i);
        }
        cnt[0]=1;
        dfs(1,0);

        cout<<ans<<"\n";
    }
}