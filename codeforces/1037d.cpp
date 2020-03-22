#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define scll(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double pi=acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=2e5+5;

vector<int> adj[lmt];
vector<int> sol1,sol2,od;
vector<bool> vis(lmt,false);

bool cmp(int a,int b){
    return od[a]<od[b];
}

int main(){
    fast
    ll n; cin>>n;
    ll a,b;
    loop(i,n-1){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    sol1.resize(n);
    od.resize(n+1);
    loop(i,n) {
        cin>>sol1[i];
        od[sol1[i]]=i;
    }
    for(int i=1; i<=n; i++)sort(all(adj[i]),cmp);

    queue<int> q;
    q.push(1);
    vis[1]=true;
    while(q.size()){
        int rt = q.front(); q.pop();
        sol2.pb(rt);
        for(int c: adj[rt]){
            if(!vis[c]){
                vis[c]=true;
                q.push(c);
            }
        }
    }
    bool ok=true;
    for(int i=0; i<n; i++){
        if(sol1[i]!=sol2[i]){
            ok=false; break;
        }
    }
    cout<<(ok?"Yes":"No")<<"\n";
}