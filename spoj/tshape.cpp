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
#define PI 3.1415926535897934384626433834795
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

int const lmt=1e5+5;

ll arr[lmt][34];
ll sum[34];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll n,ele,j; cin>>n;
    for(int i=0; i<n; i++){
        cin>>ele;j=0; 
        while(ele){
            if(ele&1)arr[i][j]=1;
            ele = ele/2;
            j++;
        }
    }
    for(int j=0; j<34; j++)sum[j]=arr[0][j];

    for(int i=1; i<n; i++){
        for(int j=0; j<34; j++){
            if(arr[i][j]==1){
                arr[i][j]=i+1;
            }else{
                arr[i][j]=arr[i-1][j];
            }
            sum[j] += arr[i][j];
        }
    }
    ll ans = 0,val=1;
    for(j=0; j<34; j++){
        ans += sum[j]*val;
        val = val*2;
    }
    cout<<ans<<"\n";
}