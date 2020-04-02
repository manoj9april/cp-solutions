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

ll a,b,p,n;
string s;

// ll dp[lmt];
bool check(ll mid){
    // dp[mid]=0;
    ll sum=(s[mid]=='A'? a:b);
    bool ok=false;
    for(int i=mid+1; i<n; i++){
        if(s[i]!=s[i-1]){
            sum += (s[i]=='A'? a:b);
            // pt(sum);
            // ok=true;
        }
    }
    if(s[n-1]!=s[n-2]) sum -= (s[n-1]=='A'? a:b);
    // if(mid<n-1)sum += (s[mid]=='A'? a:b);

    return (sum<=p);
}

int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
	// #endif
    fast

    test{
        cin>>a>>b>>p;
        cin>>s;
        n = s.length();
        // pt("new case");
        ll lo=0,hi=n-1,mid;
        while(lo<=hi){
            mid = lo + (hi - lo)/2;

            if(check(mid)) hi=mid-1;
            else lo = mid+1;
        }
        if(lo==n)lo=n-1;
        cout<<lo+1<<"\n";
    }
}


/*

// 

*/