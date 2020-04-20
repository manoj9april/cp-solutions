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

ll const N=4,x=4;
ll tem[N][N],res[N][N];
ll f[N], g[N][N];

void matexpo(ll g[N][N], ll ex){
	int i, j, k;
	if (ex == 1) return ;
	ini(tem,0);
	loop(i, x) tem[i][i]=1;

	while(ex){
		if(ex&1){
			loop(i, x) loop(j, x) { res[i][j] = 0; loop(k, x) res[i][j] += tem[i][k]*g[k][j]%mod;}
			loop(i, x) loop(j, x) tem[i][j] = (res[i][j]%mod);
		}
		// g= g*g
		loop(i, x) loop(j, x) { res[i][j] = 0; loop(k, x) res[i][j] += g[i][k]*g[k][j]%mod;}
		loop(i, x) loop(j, x) g[i][j] = (res[i][j]%mod);

		ex = ex/2;

	}
	loop(i, x) loop(j, x) g[i][j] = (tem[i][j]%mod);

}


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;

void inis(){
	f[0]=1;
	
	ini(g,0);
	g[0][0]=16;
	g[1][0]=9;
	g[2][0]=4;
	g[3][0]=1;

	for(int i=0; i<N-1; i++) g[i][i+1]=1;
}

ll cal(ll n){
	if(n<0) return 0;
	if(n==0) return 1;
	inis();
	matexpo(g,n);

	return g[0][0];
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    
    ll n; cin>>n;


    ll ans=0;
    if(n%10 <5) ans = cal(n/10-4);
    n /= 10;

    loop(i,4){
    	ans = (ans + cal(n-i))%mod;
    }
    // pt("jdjhfkj");
    pt(ans);
    
}


/*



*/



