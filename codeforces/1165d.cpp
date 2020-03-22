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

int const lmt=1e5+5;

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////


int main(){
    fast
    test
    {
        ll n; cin>>n;
        vi a(n),b;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        bool flag=1;
        sort(a.begin(),a.end());
        ll ans=a[0]*a[n-1];
        for(ll i=2; i<=sqrt(ans); i++){
            if(ans%i==0){
                b.pb(i);
                if(ans/i != i) b.push_back(ans/i);
            }
        }
        sort(all(b));
        cout<<(a==b?ans:-1)<<"\n";
    }
}


/*



*/