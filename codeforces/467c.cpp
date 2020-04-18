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
int const lmt=5e3+5;

ll dp[lmt][2];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n,m,k; cin>>n>>m>>k;
    ll a[n+1];
    a[0]=0;
    loop1(i,n) cin>>a[i], a[i]+=a[i-1];

    int flag=0;
    loop(kk,k+1){
        loop(i,n+1){
            ll &ret = dp[i][flag];
            if(i<m || kk==0) ret = 0;
            else{
                ret = max(dp[i-1][flag], a[i]-a[i-m]+dp[i-m][1-flag]);
            }
        }
        flag = 1-flag;
    }
    pt(dp[n][1-flag]);
}


/*

// 



*/



