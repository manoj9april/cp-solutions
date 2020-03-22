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

int const lmt=1e3+5;

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////

ll deg[lmt];

int main(){
    fast
    
    
        ll n,m,k;
        cin>>n>>m>>k;
        ll a,b,v,u;
        cin>>a>>b;
        for(int i=0; i<m; i++){
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
        }
        k = k - (k%2);
        ll cnt=0;
        for(int i=1; i<=n; i++){
            if(deg[i]>k){
                cout<<"-1\n";
                return 0;
            }else if(deg[i]%2){
                cnt++;
            }
        }
        if(cnt==0){
            cout<<"0\n";
            return 0;
        }
        if(cnt && !k){
            cout<<"-1\n";
            return 0;
        }
        if((cnt%k)%2){
            cout<<"-1\n";
            return 0;
        }
        
        ll ans = b*cnt;
        cnt += k-1;
        ans += a*(cnt/k);
        cout<<(ans)<<"\n";
    
}


/*



*/