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
vi adj[lmt];
int deg[lmt],dis[lmt];
bool vis[lmt];
//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////


int main(){
    fast
    ll n,k,a,b;
    cin>>n>>k;
    ini(vis,false);

    for(int i=1; i<n; i++){
        cin>>a>>b;
        deg[a]++;
        deg[b]++;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(deg[i]==1)q.push(i) , vis[i]=true;
        else if(deg[i]==2){
            cout<<"No\n";
            //pt("1");
            return 0;
        }
    }

    int cnt=0,root=inf;
    while(!q.empty()){
        int p = q.front(); q.pop();

        for(auto c: adj[p]){
            if(!vis[c]){
                q.push(c);
                vis[c]=true;
                dis[c]=dis[p]+1;
                if(dis[c]==k) root=c,cnt++;
            }
        }

    }
    /*
    for(int i=1; i<=n; i++){
        cout<<i<<" ===> "<<dis[i]<<"\n";
    }
    */
    if(cnt!=1){
        cout<<"No\n";
        //pt(root);
    }else{
        cout<<"Yes\n";
    }
}


/*

14 2
1 4
2 4
3 4
4 13
10 5
11 5
12 5
14 5
5 13
6 7
8 6
13 6
9 6


*/