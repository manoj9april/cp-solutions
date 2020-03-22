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

ll a[lmt];

int main(){
    fast
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        loop(i,n){
            cin>>a[i];
        }
        if(n%2){
            cout<<"NO\n";
            continue;
        }
        bool ok=true;
        for(int i=0,j=n/2; i<n/2; i++,j++){
            if(a[i]==-1 && a[j]==-1){
                a[i]=a[j]=1;
            }else if(a[i]==-1){
                a[i]=a[j];
            }else if(a[j]==-1){
                a[j]=a[i];
            }else{
                if(a[i]!=a[j]){
                    ok=false;break;
                }
            }
        }
        if(!ok){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}