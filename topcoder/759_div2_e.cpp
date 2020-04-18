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
int const lmt=1e5+5;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n,m;
    cin>>n>>m;
    string s[n];
    ll a[n][m],L[n][m],R[n][m],U[n][m],D[n][m];
    loop(i,n){
        loop(j,m){
            if(s[i][j]=='.')a[i][j]=0;
            else a[i][j]=1;
        }
    }

    // left, upper
    loop(i,n){
        loop(j,m){
            ll ret = L[i][j];
            if(j==0) ret=a[i][j];
            else{
                ret = L[i][j-1] + a[i][j];
            }

            if(i==0) U[i][j] = a[i][j];
            else U[i][j] = U[i-1][j] + a[i][j];
        }
    }
    // right, down
    for(int i=n-1; i>=0; i--){
        for(int j=m-1; j>=0; j--){
            if(j==m-1) R[i][j]=a[i][j];
            else{
                R[i][j] = R[i][j+1] + a[i][j];
            }

            if(i==n-1) D[i][j]=a[i][j];
            else{
                D[i][j] = D[i+1][j] + a[i][j];
            }
        }
    }
    
    ll cnt=0;
    loop(i,n){
        loop(j,m){
            if(L[i][j]==0 && R[i][j]==0 && U[i][j]==0 &&D[i][j]==0 ) cnt++;
        }
    }

    pt(cnt);
}


/*

// 



*/



