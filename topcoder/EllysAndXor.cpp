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


class EllysAndXor {
	public:
	int getMax(vector <int> a) {
		// ll ans = v[0];
		int n = a.size();
		ll ans=-1;
		loop(i,1<<(n-1)){
			ll cur = a[0];

			loop(j,n-1){
				if( (i>>j)&1) cur ^= a[j+1];
				else cur &= a[j+1];
			}
			ans = max(ans,cur);
		}

		return ans;
	}
};

// int main(){
// 	#ifndef ONLINE_JUDGE
//     freopen("../input.txt", "r", stdin);
//     freopen("../output.txt", "w", stdout);
// 	#endif

// 	EllysAndXor solver;
// 	int n; cin>>n;
// 	vector <int> numbers(n);

// 	loop(i,n) cin>>numbers[i];
// 	int ans = solver.getMax(numbers); 
// 	pt(ans);
// }
