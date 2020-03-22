
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

int const lmt=1e5+5;


int main(){
    fast
    ll n,a,b;
    cin>>n>>a>>b;
    ll arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    ll ans=0;
    bool ok=true;
    for(int i=0,j=n-1; i<=j; i++,j--){
        if(arr[i]==arr[j]){
            if(arr[i]==2){
                ans += min(a,b);
                if(i!=j) ans+=min(a,b);

            }
        }else{
            if(arr[i]!=2 && arr[j]!=2){
                ok=false; break;
            }else{
                if(arr[i]==0 || arr[j]==0){
                    ans += a;
                }else if(arr[i]==1 || arr[j]==1){
                    ans += b;
                }
            }
        }
    }
    if(ok){
        cout<<ans<<"\n";
    }else{
        cout<<"-1\n";
    }
}
