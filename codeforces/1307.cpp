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
int const lmt=2e5+5;

vi adj[lmt];
int n,m,k;

void bfs(int *dist, int p){

    fill(dist+1,dist+n+1,inf);
    
    queue<int> q;
    dist[p]=0;
    q.push(p);

    while(!q.empty()){
        int pr = q.front(); q.pop();

        for(int c: adj[pr]){
            if(dist[c]==inf){
                dist[c] = dist[pr]+1;
                q.push(c);
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    cin>>n>>m>>k;
    int sp[k];
    loop(i,k) cin>>sp[i];
    ll a,b;
    loop(i,m){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    int d1[n+1], dn[n+1];
    bfs(d1, 1);
    bfs(dn, n);

    vpii v;
    loop(i,k){
        int x = d1[sp[i]];
        int y = dn[sp[i]];
        v.pb({x-y,sp[i]});
    }

    sort(all(v));

    int ans=0,max_x=-inf;
    loop(i,k){
        int idx = v[i].S;
        ans = max(ans, max_x + dn[idx]);
        max_x = max(max_x, d1[idx]);
    }
    // loop1(i,n) cout<<dn[i]<<" ";
    // pt("");
    pt(min(d1[n],ans+1));

}


/*

// 



*/



