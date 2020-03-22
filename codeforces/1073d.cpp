#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;
#define pt(x) cout<<x<<"\n";

#define mp make_pair
#define pb push_back
#define f first
#define s second


#define inf (int)1e9
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


//////////////////////////////////////////////////////////////////////////////////////////
//                      CONSTANTS
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=2e5+5;
ll a[lmt];
bool ck[lmt];
//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////


int main(){
    fast
    ll n,m;
    cin>>n>>m;

    sl st;
    loop(i,n)cin>>a[i];
    ll ans=0;
    ini(ck,true);
    ll nn=n;
    while(nn){
        
        ll cnt=0,sum=0;
        loop(i,n){
            if(ck[i]){
                if(a[i]<=m){
                    sum += a[i];
                    cnt++;
                }else{
                    ck[i]=false;
                    nn--;
                }
            }
        }
        if(sum)ans += cnt*(m/sum);
        if(sum>m){
            loop(i,n){
                if(a[i]<=m){
                    m -= a[i];
                    ans++;
                }
            }
        }else{
            if(sum)m -= ((m/sum)*sum);
        }
    }

    cout<<ans<<"\n";
}


/*



*/