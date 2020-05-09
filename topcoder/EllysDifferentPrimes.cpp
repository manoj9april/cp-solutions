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


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e8+5;
vector<bool> prime(lmt, 1);
int we[10];
void sv(ll n){
	for(ll i=2; i*i <= n; i++){

		if(prime[i]){
			for(ll j=i*i; j<=n; j+=i)prime[j]=0;
		}
	}
}

bool check(ll n){
	ini(we,0);
	while(n){
		ll val = n%10;
		if(we[val])return 0;
		we[val]=1;
		n = n/10;
	}
	return 1;
}

class EllysDifferentPrimes {
	public:
	int getClosest(int N) {
		ll val;
		if(N<=2000000)val=N;
		else val = 2000000;
		sv(N+2*val);
		loop(i,2*val){
			if( (N-i)>1 && prime[N-i] && check(N-i)) return (N-i);
			else if(prime[N+i] && check(N+i)) return (N+i);
		}

		return 2;
	}
};

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("../input.txt", "r", stdin);
// 	freopen("../output.txt", "w", stdout);
// 	#endif
	
// 	EllysWhatDidYouGet solver;
// 	int N;
// 	cin>>N;
// 	int ans = solver.getCount(N); 
// 	pt(ans);

// 	// dbg(check(101));
// }
