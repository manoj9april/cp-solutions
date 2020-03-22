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

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////

map<pii,int> ind;
ll r[lmt],l[lmt],u[lmt],d[lmt];

int main(){
    fast
    ll n; cin>>n;
    string s; cin>>s;

    ll x,y; cin>>x>>y;

    if(n<abs(x)+abs(y)){
        cout<<-1<<"\n";
        return 0;
    }

    ll st = n-abs(x)+abs(y);
    if(st&1){
        cout<<-1<<"\n";
        return 0;
    }
    
    for(int i=0; i<n; i++){
        if(s[i]=='U'){
            u[i+1]=1;
        }
        if(s[i]=='D'){
            d[i+1]=1;
        }
        if(s[i]=='L'){
            l[i+1]=1;
        }
        if(s[i]=='R'){
            r[i+1]=1;
        }
    }

    for(int i=1; i<=n; i++){
        r[i] += r[i-1];
        l[i] += l[i-1];
        u[i] += u[i-1];
        d[i] += d[i-1];
    }

    ll lo=0,hi=n,mid;

    while(lo<=hi){

        mid = lo + (hi-lo)/2;

        bool ok=false;
        for(int i=0; i+mid<n; i++){
            int j=
        }
    }
}


/*



*/