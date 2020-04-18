#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl
#define pt(x) cout<<x<<"\n"
#define pts(x) cout<<x<<" "

#define mp make_pair
#define pb push_back
#define F first
#define S second


#define inf (int)1e9
#define infll 1e18
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007


#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test   int t; cin>>t; while(t--)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef map<ll,ll> mll;
typedef set<ll> sl;


int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;
ll n,k;
ll ans[lmt],vis[lmt],ind[lmt];
pair< pii, int>  lvl[lmt]; // lvl , subtree, index
vi adj[lmt];

void dfs(int p){
	vis[p]=1;
	lvl[p].S = p;
	lvl[p].F.S=1;
	for(int c: adj[p]){
		if(!vis[c]){
			lvl[c].F.F = lvl[p].F.F - 1;
			dfs(c);
			lvl[p].F.S += lvl[p].F.S;
		}
	}
}

void inis(){
	ini(vis,0);
}

void cal(int p){
	vis[p]=1;

	ans[p] = (ind[p]? 1:0);

	for(int c:adj[p]){
		if(!vis[c]){
			cal(c);
			ans[p] += ans[c];
		}
	}
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n,k; cin>>n>>k;

    ll a,b;
    loop(i,n-1){
    	cin>>a>>b;
    	adj[a].pb(b);
    	adj[b].pb(a);
    }

    lvl[1].F.F=0;
    dfs(1); // lvltree

    sort(lvl+1, lvl+n+1);

    loop1(i,k){
    	int idx = lvl[i].S;
    	ind[idx] = 1;
    }
    inis();
    cal(1);

    ll res  =0;
    loop1(i,n){
    	if(!ind[i]) res += ans[i];

    	// if(!ind[i])pts(ans[i]);
    	// else pts("00");
    }
    // pts("sdbjb");
    pt(res);
}


/*

// 



*/



