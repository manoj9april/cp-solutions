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

int W;
bool a[20][20];
ll dp[20][1<<20];

ll solve(int w, int num){
    if(w==W && num==0) return 1;
    if(dp[w][num]!=-1) return dp[w][num];
    ll ans=0;
    for(int i=0; i<W; i++){
        if((num & (1<<i) ) && a[w][i]){
            ans += solve(w+1, (num^(1<<i)));
        }
    }
    return dp[w][num]=ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        ini(dp,-1);
        cin>>W;
        int ele;
        for(int i=0; i<W; i++){
            for(int j=0; j<W; j++){
                cin>>ele;
                a[i][j] = (ele==1);
            }
        }
        
        ll ans = solve(0,(1<<W)-1);
        cout<<ans<<"\n";
    }
}