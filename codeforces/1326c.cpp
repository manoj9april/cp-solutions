#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl;
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
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;



int main(){
    
    fast

    ll n,k; cin>>n>>k;
    
    pll pp[n];
    for(int i=0; i<n; i++){
        cin>>pp[i].f;
        pp[i].s = i;
    }
    sort(pp, pp+n);
    reverse(pp, pp+n);

    ll pos[k];
    ll ans=0;
    for(int i=0; i<k; i++){
        ans += pp[i].f;
        pos[i]=pp[i].s;
    }
    cout<<ans<<" ";
    ll md = 998244353l;
    ans=1;
    sort(pos,pos+k);
    for(int i=1; i<k; i++) ans = (ans*(pos[i]-pos[i-1]))%md;
    cout<<ans<<"\n";

}


/*

// 

*/