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

vi adj[lmt];
int dis[lmt],mark[lmt],deg[lmt];
int vis[lmt];

void dfs(int p){
	vis[p]=1;
	for(int c:adj[p]){
		if(!vis[c]){
			dis[c]=dis[p]+1;
			dfs(c);
		}
	}
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n; cin>>n;
    ll a,b;

    loop(i,n-1){
    	cin>>a>>b;
    	a--; b--;
    	adj[a].pb(b);
    	adj[b].pb(a);
    	deg[a]++; deg[b]++;
    }
    int rt=0;
    while(deg[rt]>1)rt++;
    dis[rt]=0;
    dfs(rt);

    ini(mark,0);

    int ans = n-1,mn=1; 
    loop(i,n){
    	if(deg[i]==1){
    		int c = adj[i][0];
    		mark[c]=1;
    		ans--;
    		if(i!=rt && dis[i]%2)mn=3;
    	}
    }
    loop(i,n){
    	// pts(mark[i]);
    	if(mark[i]) ans++;
    }
    // pt("");
    pts(mn);
    pt(ans);

}


/*

// 



*/



