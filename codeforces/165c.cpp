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
int const lmt=1e5+5;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    ll k;
    string s; cin>>k>>s;

    ll n = s.length();
    int bk[n],fr[n];
    ll cnt=0,ans=0;
    if(k==0){
    	cnt=0,ans=0;
    	loop(i,n){
    		if(s[i]=='1'){
    			// debug(i,cnt);
    			ans += (cnt*(cnt+1)/2);
    			cnt=0;
    		}else{
    			cnt++;
    		}
    	}
    	ans += (cnt*(cnt+1)/2);
    	pt(ans);
    	return 0;
    }

    loop(i,n){
    	cnt++;
    	if(s[i]=='1'){
    		bk[i]=cnt;
    		cnt=0;
    	}
    }
    cnt=0;
    loop(i,n){
    	cnt++;
    	if(s[n-1-i]=='1'){
    		fr[n-1-i]=cnt;
    		cnt=0;
    	}

    	// pts(bk[i]);
    }
    // pt("");

    ll r=0;
    cnt=1;

    loop(i,n){
    	// pts(fr[i]);
    	if(s[i]=='1'){
    		cnt--;
    		r = max(r,i);
    		while(r<n && cnt<k){
    			if(s[r]=='1'){
    				cnt++;
    			}
    			r++;
    		}
    		if(cnt==k){
    			ans += 1ll*bk[i]*fr[r-1];
    		}
    	}
    }

    pt(ans);
}


/*



*/



