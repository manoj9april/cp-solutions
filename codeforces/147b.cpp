#include<bits/stdc++.h>

using namespace std;

#define ll int
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
int const lmt=3e2+5;
int const N = lmt;
int x =lmt;

ll adj[lmt][lmt],g[lmt][lmt];
ll tem[N][N],res[N][N];

void matexpo(ll g[N][N], ll ex){
	int i, j, k;
	if (ex == 1) return ;
	loop(i,x) loop(j,x) tem[i][j]=-inf;
    loop(i,x) tem[i][i]=0;

	while(ex){
		if(ex&1){
			loop(i, x) loop(j, x) { res[i][j] = -inf; loop(k, x) res[i][j] = max(res[i][j],tem[i][k]+g[k][j]);}
			loop(i, x) loop(j, x) tem[i][j] = (res[i][j]);
		}
		// g= g*g
		loop(i, x) loop(j, x) { res[i][j] = -inf; loop(k, x) res[i][j] = max(res[i][j],g[i][k]+g[k][j]);}
		loop(i, x) loop(j, x) g[i][j] = (res[i][j]);

		ex = ex/2;

	}
	loop(i, x) loop(j, x) g[i][j] = (tem[i][j]);

}

bool cycle(ll k){
	loop(i,lmt) loop(j,lmt) g[i][j] = adj[i][j];
	matexpo(g,k);

	loop1(i,lmt-1)if(g[i][i]>0) return true;

	return false;
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n,m;
    cin>>n>>m;
    x=n;
    int xx,yy;
    loop(i,x) loop(j,x) adj[i][j]=-inf;
    loop(i,x) adj[i][i]=0;
    loop(i,m){
    	cin>>xx>>yy;
    	xx--; yy--;
    	cin>>adj[xx][yy]>>adj[yy][xx];
    }

    ll lo=1,hi=n,mid;
    while(lo<=hi){
    	mid = lo + (hi-lo)/2;

    	if(cycle(mid)) hi=mid-1;
    	else lo = mid+1;
    }

    pt((lo<=n? lo : 0));
}


/*



*/



