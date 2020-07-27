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
ll n,m,k;
set<int> adj[lmt];
int take[lmt];
int deg[lmt],vis[lmt],part[lmt];
int ok=1,got_c;
vi v;

void cycle(int st, int p){
	if(st==p){
		return;
	}
	v.pb(p);
	cycle(st,part[p]);
}
void call(int p, int par){
	if(!ok) return;
	vis[p]=1;
	// dbg(p);
	part[p]=par;
	for(int c: adj[p]){
		if(!ok) return;
		if(c==par)continue;
		if(vis[c]==1){
			v.pb(c);
			// dbg(c);
			cycle(c,p);
			ok=0;return;
		}
	}
	for(int c: adj[p]){
		if(!ok) return;
		if(c==par)continue;
		
		if(vis[c]==0) call(c,p);
	}
	vis[p]=2;
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    cin>>n>>m>>k;

    int a,b;
    loop(i,m){
    	cin>>a>>b;
    	adj[a].insert(b);
    	adj[b].insert(a);
    	deg[a]++; deg[b]++;
    }
    // pt("jdhjf");
    // debug(n,m,k);
    if( (n-1)==m){
    	// pt("helo");
    	queue<int> q;
    	loop1(i,n)if(deg[i]==1){q.push(i); take[i]=1;}	
    	while(!q.empty()){
    		int c=-1;
    		int p = q.front(); q.pop();
    		for(int par: adj[p]){
    			c=par;
    		}
    		if(c!=-1){
	    		adj[c].erase(p);
				if(!take[c])take[c] = -take[p];
				if(adj[c].size()==1)q.push(c);
			}
    	}
    	pt("1");
    	k = (k+1)/2;
    	loop1(i,n){
    		if(!k)break;
    		if(take[i]==1){
    			pts(i); k--;
    		}
    	}
    	pt("");

    }else{
    	call(1,-1);

    	int step=1;
    	if(v.size()>k){
    		step=2;
    		pt("1");
    		k = (k+1)/2;
    	}else {pt("2"); pt(v.size());}

    	// pt((v.size()+1)/2);
    	for(int i=0; i<v.size(); i++){
    		// if(!k)break;
    		// k--;
    		pts(v[i]);	
    	}
    }
    
}


/*


*/



