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

int fre[20][20];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    ll n,m,k; cin>>n>>m>>k;

    int val[n];
    loop(i,n) cin>>val[i];

    ll a,b,c;
    loop(i,k){
        cin>>a>>b>>c;
        a--;b--;
        fre[a][b]=c;
    }

    ll dp[1<<n][n];

    
    ini(dp,0);
    ll ans=0;

    loop(i,n)dp[1<<i][i]=val[i];

    loop(num,1<<n){
        if(__builtin_popcount(num)>m) {continue;}
        loop(i,n){
            ll &ret = dp[num][i];
            if(num & (1<<i)){
                
                ll nnum = (num^(1<<i));
                loop(j,n){
                    if(nnum & (1<<j))
                        ret = max(ret, dp[nnum][j] + val[i]  + fre[j][i]);
                }
            }
            if(__builtin_popcount(num)== m)
                ans = max(ret,ans);
        }
    }
    pt(ans);
}


/*

// 



*/



