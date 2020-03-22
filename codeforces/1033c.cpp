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
#define rloop(i,n) rev_rep(i,n-1,0,1)
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

int const lmt=1e5+5;

ll state[lmt],a[lmt],b[lmt];
ll dp[lmt];

int main(){
    fast
    ll n; cin>>n;
    ini(dp,-1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        b[a[i]]=i;
        if(a[i]==n)dp[i]=0;
    }
    for(int idx=n; idx>=1; idx--){
        int i = b[idx];
        if(dp[i]!=-1) continue;
        int ok=0;
        for(int j=i%a[i]; j<=n; j+=a[i]){
            if(a[j]>a[i] && !dp[j]){
                ok=1;
                break;
            }
        }
        dp[i]=ok;
    }
    /*
    for(int i=1; i<=n; i++){
        if(dp[i]!=-1) continue;
        int ok=0;
        for(int j=i-a[i]; j>=1; j-=a[i]){
            if(a[j]>a[i] && !dp[j]){
                ok=1;
                break;
            }
        }
        dp[i]=(dp[i]|ok);
    }
    */
    for(ll i=1; i<=n; i++){
        
        if(dp[i]){
            cout<<"A";
        }else{
            cout<<"B";
        }
    }
    cout<<"\n";
}


/*
6
5 3 6 1 4 2

*/