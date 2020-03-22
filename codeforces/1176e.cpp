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
int const lmt=2e5+5;

vi adj[lmt];
int cnt[lmt],vis[lmt],taken[lmt];

ll ans;
void dfs(int i, int l){
    vis[i]=1;
    taken[i]=l;
    // dbg(i);
    ans += l;
    for(int j=0; j<adj[i].size(); j++){
        int c = adj[i][j];
        if(!vis[c]) dfs(c,(l+1)%2);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    test{
        ll n,m,a,b;
        cin>>n>>m;
        for(int i=0; i<=n; i++){
            adj[i].clear();
            cnt[i]=taken[i]=vis[i]=0;
        }
        for(int i=0; i<m; i++){
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
            cnt[a]++;cnt[b]++;
        }
        ll rt=1;
        for(int i=1; i<=n; i++){
            if(cnt[i]==1){
                rt=i; break;
            }
        }
        ans=0;
        // dbg(adj[1].size());
        dfs(rt,0);
        ll ck=0;
        if(ans > n/2) {ans = n-ans; ck=1;}
        cout<<ans<<"\n";
        for(int i=1; i<=n; i++){
            if(taken[i]-ck)cout<<i<<" ";
        }
        cout<<"\n";
    }   
}


/*



*/