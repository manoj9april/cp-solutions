#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define sc2i(t,k) scanf("%d%d",&t,&k)
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
typedef unsigned long int ul;
typedef long long int ll;
typedef unsigned long long int  ull;

vi adj[100000+1];

int dp[100000+1][2];

int dfs(int p, int taken, int par){
    if(dp[p][taken]!=-1) return dp[p][taken];
    
    dp[p][taken]=taken;
    for(int c: adj[p]){
        if(c!=par){
            if(taken==1) dp[p][taken]+=min(dfs(c,0,p), dfs(c,1,p));
            else dp[p][taken]+= dfs(c,1,p);
        }
    }
    return dp[p][taken];
}

int main(){
    int n; sci(n);
    int a,b;
    if(n<2){
        printf("%d\n",n);
    }else{
        rep(i,1,n-1,1){
            sc2i(a,b);
            adj[a].pb(b);
            adj[b].pb(a);
        }
        ini(dp,-1);

        printf("%d\n",min(dfs(a,0,-1), dfs(a,1,-1)));
        }
}