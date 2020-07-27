#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " = " << x << endl
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



//===========================DEBUG======================//
#define XOX 1
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

//================================================================//



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=2e5+5;

struct edge{
	int f,s,val;
};

edge e[lmt];
map<pii, int> mm;

set<int> adj[lmt];
int vis[lmt];
int out[lmt];

// void dfs(int p){
// 	vis[p]=1;

// 	for(int c: adj[p]){
// 		if(vis[c]==0){
// 			int eidx = mm[{p,c}];
// 			if(e[eidx].val){
// 				if(e[eidx].f==p && a[eidx].s == c)dfs(c);
// 			}else{
// 				e[eidx]={p,c,1};
// 				dfs(c);
// 			}
// 		}else if(vis[c]==1){
// 			int eidx = mm[{p,c}];
// 			if(e[eidx].val){
// 				if(e[eidx].f==p && a[eidx].s == c)
// 			}else{
// 				e[eidx]={p,c,1};
// 				dfs(c);
// 			}
// 		}
// 	}
// }

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    test{
    	ll n,m; cin>>n>>m;
    	
    	int u,v,c;
    	loop(i,n+1){
    		adj[i].clear();
    		out[i]=0;
    	}
    	mm.clear();
    	loop(i,m){
    		cin>>c>>u>>v;
    		mm[{u,v}]=i;
    		mm[{v,u}]=i;
    		e[i] = {u,v,c};
    		adj[u].insert(v);
    		adj[v].insert(u);

    		if(c){
    			out[u]++;
    		}
    	}
    	queue<int> q;
    	loop1(i,n){
    		if(!out[i])q.push(i);
    	}

    	while(!q.empty()){
    		int p = q.front(); q.pop();
    		for(int c:adj[p]){
    			int eidx = mm[{p,c}];
    			if(!e[eidx].val){
    				e[eidx]={c,p,1};
    			}else{
    				out[c]--;
    			}
    			
    			// debug(c,p);
    			
    			if(!out[c])q.push(c);
    			adj[c].erase(p);
    		}
    		adj[p].clear();
    	}
    	int ok=1;
    	loop1(i,n){
    		if(out[i]){ok=0; break;}
    	}
    	if(!ok){
    		pt("NO"); continue;
    	}else pt("YES");

    	loop1(i,n){
    		if(adj[i].size()){
    			q.push(i);
		    	while(!q.empty()){
		    		int p = q.front(); q.pop();
		    		for(int c:adj[p]){
		    			int eidx = mm[{p,c}];
		    			e[eidx]={p,c,1};
		    			
		    			adj[c].erase(p);
		    		}
		    		adj[p].clear();
		    	}
		    }
    	}

    	loop(i,m){
    		pts(e[i].f);
    		pt(e[i].s);
    	}
    }
}


/*


*/



