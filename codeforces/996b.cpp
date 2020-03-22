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

int const lmt=1e5+5;

int arr[lmt];
int n;
bool ck[lmt];
int main(){
    cin>>n;
    int ans=1e9+8;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        ans = min(ans,arr[i]/n);
        ck[i]=false;
    }

    vector<int> v;
    for(int i=0; i<n; i++){
        if(arr[i]/n == ans)ck[i]=true;
    }
    bool ok=false;
    for(int i=0; i<n; i++){
        if(ck[i] && (arr[i]%n)<= i){
            ans=i;ok=true;
            break;
        }
    }
    if (ok){
        cout<<ans+1<<"\n";
        return 0;
    }
    
    for(int i=0; i<n; i++){
        if(ck[i]){
            cout<<i+1<<"\n";
            break;
        }
    }
}