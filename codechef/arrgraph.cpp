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
typedef pair<ll, ll> pll;
//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e2+5;

ll a[lmt],mark[lmt];
bool pr[lmt];
mii occ;
int main(){
    fast
    ll t; cin>>t;
    ini(pr,true);
    for(int i=2; i<=50; i++){
        if(pr[i]){
            for(int j=i+i; j<=50; j+=i) pr[j]=0;
        }
    }
    while(t--){
        ll n; cin>>n;
        ll ele;
        occ.clear();
        for(int i=0; i<n; i++){ cin>>a[i]; occ[a[i]]++;}

        bool ok=true;
        ini(mark,false);
        for(int i=0; i<n; i++){
            if(mark[i]) continue;
            for(int j=0; j<n; j++){
                if(__gcd(a[j],a[i])==1) {mark[i]=mark[j]=true; break;}
            }
            if(!mark[i]){ ok=false; break;}
        }
        if(ok){
            cout<<0<<"\n"<<a[0]<<" ";
        }else{
            //cout<<"jkhd\n";
            cout<<1<<"\n";
            for(ll i=50; i>=2; i--){
                bool oo=true;
                for(int j=0; j<n; j++){
                    if(__gcd(i,a[j])!=1){
                        oo=false; break;
                    }
                }
                if(oo){
                    cout<<i<<" "; break;
                }
            }
        }

        for(int i=1; i<n; i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
}