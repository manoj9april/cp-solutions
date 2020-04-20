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
int const lmt=1e5+5;


class ThreeNeighbors {
	public:
	vector <string> construct(int N) {
		int W=50;
		string w="";
		loop(i,W) w+= 'X';


		vector<string> a(W, w);

		ll cnt=N;
		// int m = W,n=W,k=0,l=0,i;
		int flag=0,idx=50;
		loop(i,W){
			loop(j,W){
				if(!cnt){
					for(int k=j; k<W; k++) a[i][k]='.';
					if(i<W-1)for(int k=j+1; k<W; k++) a[i+1][k]='.';
					idx=i+2;
					flag=1;
					break;
				}
				if( (i%4 == 1) || (i%4 == 2) ) {a[i][j]='.'; cnt--;}
			}
			if(flag) break;
		}
		while(idx<W){
			loop(j,W) a[idx][j]='.';
			idx++;
		}
		return a;
	}
};

// int main(){
// 	#ifndef ONLINE_JUDGE
// 	freopen("../input.txt", "r", stdin);
// 	freopen("../output.txt", "w", stdout);
// 	#endif
	
// 	ThreeNeighbors solver;
// 	int N;
// 	cin>>N;
// 	vector <string> ans = solver.construct(N); 

// 	int W=10;
// 	loop(i,W){
//     	loop(j,W){
//     		cout<<ans[i][j];
//     	}
//     	pt("");
//     }
// }
