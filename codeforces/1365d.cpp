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


int dirx[] = { 0,0,1,-1 };
int diry[] = { 1,-1,0,0 };



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
string s[52];
int n,m;
int vis[52][52];


bool valid(int i, int j){
	if(i>=0 && i<n && j>=0 && j<m) return true;

	return false;
}

void guard(int i, int j){
	loop(k,4){
		int ni = i + dirx[k];
		int nj = j + diry[k];
		if(valid(ni,nj) && s[ni][nj]=='.')s[ni][nj]='#';
	}
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    // fast
    // int hh=0;
 	test{
 		// hh++;
 		cin>>n>>m;
 		ini(vis,0);
 		loop(i,n){
 			cin>>s[i];
 		}
 		int b=0, g=0;
 		loop(i,n)loop(j,m){
 			if(s[i][j]=='B') guard(i,j); 

 			if(s[i][j]=='B')b++;
 			else if(s[i][j]=='G')g++;
 		}

 		// pt("TEST=======");
 		// loop(i,n){
 		// 	pt(s[i]);
 		// }

 		int cntb=0,cntg=0;
 		if(s[n-1][m-1]=='#'){
 			if(cntg==g)pt("Yes");
 			else pt("No");
 			continue;
 		}
 		queue<int> q;
 		q.push(n-1);
 		q.push(m-1);
 		vis[n-1][m-1]=1;

 		while(!q.empty()){
 			int pi = q.front(); q.pop();
 			int pj = q.front(); q.pop();

 			if(s[pi][pj]=='B'){cntb++; break;}
 			else if(s[pi][pj]=='G')cntg++;

 			loop(k,4){
 				int ni = pi + dirx[k];
 				int nj = pj + diry[k];
 				if(valid(ni,nj) && s[ni][nj]!='#'){
 					if(!vis[ni][nj]){
 						q.push(ni); q.push(nj);
 						vis[ni][nj]=1;
 					}
 				}
 			}
 		}

 		// debug(hh,b,cntb, g, cntg);
 		if(cntb==0 && cntg==g)pt("Yes");
 		else pt("No");
 	}   
}


/*


*/



