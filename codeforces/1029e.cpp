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
#define all(a)      (a).begin(),(a).end()
#define what_is(x)  cerr << #x << " is " << x << endl;

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

int const lmt=2e5+5;
vi adj[lmt];
set<pii> st;
int dis[lmt],pp[lmt];

void dfs(int p, int par, int d){
    dis[p]=d;
    pp[p]=par;
    for(auto c: adj[p]){
        if(c!=par) dfs(c,p,d+1);
    }
}

int main(){
    fast
    int a,b,n; cin>>n;
    rep(i,1,n-1,1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    dfs(1,-1,0);
    rep(i,1,n,1){
        if(dis[i]>2)st.insert(mp(-dis[i],i));
    }
    int v;
    ll ans=0;
    while(st.size()){
        v = st.begin()->s;
        v =  pp[v];
        auto it = st.find(mp(-dis[v],v));
        if(it!=st.end()){
            st.erase(it);
        }
        ans++;
        for(auto c: adj[v]){
            it = st.find(mp(-dis[c],c));
            if(it!=st.end()){
                st.erase(it);
            }
        }
    }
    cout<<ans<<"\n";
}