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
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

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

const int lmt = 10001;
vi adj[lmt];
bool visited[lmt];
int tin[lmt],tout[lmt];
vector<pair<pii, int> >  v;
int t=0;

void dfs(int p){
    visited[p]=true;
    tin[p]=++t;
    for(int c:adj[p]){
        if(!visited[c]){
            dfs(c);
        }
    }
    tout[p]=++t;
    v.pb(mp(mp(tin[p],tout[p]), p));
}

int main(){
    int r=1;
    int te; cin>>te;
    while(te--){
    	v.clear();
        int n;cin>>n;
        for(int i=1; i<=n; i++){
        	adj[i].clear();
            int m; cin>>m;
            for(int j=0; j<m; j++){
                int c; cin>>c;
                adj[i].pb(c);
                adj[c].pb(i);
            }
        }
        ini(visited,false);
        dfs(1);
        int q,qs,qe; cin>>q;
        sort(v.begin(), v.end());
	
        cout<<"Case "<<r++<<":"<<endl;
        while(q--){
            cin>>qs>>qe;
            int lo=0; int mid,hi=v.size()-1;
            int in = min(tin[qe],tin[qs]), out = max(tout[qs],tout[qe]);

            while(lo<=hi){
                mid = lo + (hi-lo)/2;
                if(v[mid].f.f==in) break;
                else if(v[mid].f.f<in) lo = mid+1;
                else hi =mid-1;
            }
            
            while(v[mid].f.s<out) mid--;
           
            cout<<v[mid].s<<"\n";
        }
    } 

}