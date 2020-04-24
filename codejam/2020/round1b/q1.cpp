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


int dirx[] = { 0, -1, 0 ,1 };
int diry[] = { 1, 0, -1, 0 };



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
int const lmt=1e5+5;
string s;
ll X,Y;
int cnt;
void cal(ll x, ll y){
	// if(cnt>32) return;
	// cnt++;
	// debug(x,y);
	if(x==1 && y==0){
		s+='E'; return;
	}
	if(x==-1 && y==0){
		s+='W'; return;
	}
	if(x==0 && y==1){
		s+='N'; return;
	}
	if(x==0 && y==-1){
		s+='S'; return;
	}
	if(x%2){
		if(( (x-1)/2 + y/2) %2){
			s+='E';
			cal( (x-1)/2, y/2);
		}else{
			s+='W';
			cal( (x+1)/2, y/2);
		}	
	}else{
		if(( x/2 + (y-1)/2) %2){
			s+='N';
			cal( x/2, (y-1)/2);
		}else{
			s+='S';
			cal( x/2, (y+1)/2);
		}	
	}
}

void change(int sx, int sy){
	int n = s.size();
	loop(i,n){
		if(sx){
			if(s[i]=='E')s[i]='W';
			else if(s[i]=='W')s[i]='E';
		}
		if(sy){
			if(s[i]=='N')s[i]='S';
			else if(s[i]=='S')s[i]='N';
		}
	}
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
	#endif
    fast
    int T=1;
    
    test{

        cin>>X>>Y;
        
        cout<< "Case #" << T++ << ": ";

        int sx = X<0;
        int sy = Y<0;
        X = abs(X);
        Y = abs(Y);
        if((X+Y)%2==0){
        	pt("IMPOSSIBLE");
        	continue;
        }

        s = "";
        cal(X,Y);
        change(sx,sy);
		cout<<s;
        

        cout<<"\n";
    }
}