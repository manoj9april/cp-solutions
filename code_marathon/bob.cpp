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

int a[20];
int dp[20][1<<20];
int G[20][20];

int GCD(int A, int B) {
    if(B==0)
        return A;
    else
        return GCD(B, A % B);
}

int solve(int w, int num){
    if(num==0) return 0;
    if(dp[w][num]!=-1) return dp[w][num];
    int ans=INT_MAX;
    for(int i=0; i<W; i++){
        if((num & (1<<i) )){

            ans = min(ans,G[w][i]+solve(i, (num^(1<<i))));
        }
    }
    return dp[w][num]=ans;
}
 
int main(){
    int t=1;
    while(t--){
        ini(dp,-1);
        cin>>W;
        for(int i=0; i<W; i++){
            cin>>a[i];
        }
        for(int i=0; i<W; i++){
            for(int j=i+1; j<W; j++){
                G[i][j]=GCD(a[i],a[j]);
                G[j][i]=G[i][j];
            }
        }
        int ans =INT_MAX;
        int nm = (1<<W)-1;
        for(int i=0; i<W; i++){
            ans = min(ans, a[i]+solve(i,(nm^(1<<i))));
        }

        cout<<ans<<"\n";
    }
}