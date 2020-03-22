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

ll a[lmt],ttm[lmt];
ll arr[lmt];
ll n,T;

bool c2(int i, int j){
    return ttm[i]<ttm[j];
}

bool check(ll mid){
    ll t=T;
    ll cnt=0;
    for(int i=1; i<=n; i++){
        if(a[arr[i]]>=mid){
            cnt++;
            t -= ttm[arr[i]];
            if(t<0){
                cnt--; break;
            }
        }
    }
    return cnt>=mid;
}
int main(){
    fast
    cin>>n>>T;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>ttm[i];
        arr[i]=i;
    }
    sort(arr+1,arr+n+1,c2);
    vector<int> sol;
    ll lo=0,hi=n,mid;
    while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(check(mid)) lo=mid+1;
        else hi=mid-1;
    }
    cout<<hi<<"\n"<<hi<<"\n";
    ll cnt=0;
    for(int i=1; i<=n; i++){
        if(cnt==hi)break;
        if(a[arr[i]]>=hi){sol.pb(arr[i]);cnt++;}
    }
    for(int i=0; i<cnt; i++)cout<<sol[i]<<" ";
    cout<<"\n";
}