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

int const lmt=1e7+5;

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////

ll n; 

ll find(ll k){
    ll lo=1,hi=k,mid;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        if(n%mid==0)lo = mid+1;
        else hi = mid-1;
    }
    return hi;
}

int dp[lmt];

int main(){
    ini(dp,-1);
    cin>>n;
    ll st=0;
    dp[0]=0;
    for(ll i =1; i<=n; i++){
        /*
        cout<<n<<"===>";
        if(n==0){
            cout<<st<<"\n";
            break;
        }*/

        ll rtn = sqrt(i);
        ll a = find(rtn);
        if(a==1){
            ll val = i-1;
            dp[i] = dp[val]+1;
            //n = val;
        }else{
            ll val;
            if(dp[i-1]<dp[i/a]) val=i-1;
            else val = i/a;

            dp[i] = dp[val]+1;
            //n = val;
        }
        //st++;
    }
    cout<<dp[n]<<"\n";
}


/*



*/