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

int const lmt=1e3+5;

ll l[lmt],r[lmt],a[lmt];
int main(){
    fast
    ll n; cin>>n;
    for(int i=0; i<n; i++) cin>>l[i];
    for(int i=0; i<n; i++) cin>>r[i];
    ll gm = lmt+lmt;
    for(int i=0; i<n; i++){
        a[i] = n - (l[i]+r[i]);
        gm = min(gm,a[i]);
        //cout<<a[i]<<" ";
    }
    //cout<<"\n";

    for(int i=0; i<n; i++){
        ll val=0;
        for(int j=0; j<i; j++){
            if(a[j]>a[i])val++;
        }
        if(val!=l[i]){
            //dbg(i);
            cout<<"NO\n";
            return 0;
        }
        val=0;
        for(int j=i+1; j<n; j++){
            if(a[j]>a[i])val++;
        }
        if(val!=r[i]){
            //dbg(i);
            cout<<"NO\n";
            return 0;
        }
    }

    cout<<"YES\n";
    //gm = -gm + 1;
    for(int i=0; i<n; i++){
        cout<<a[i]-gm+1 << " ";
    }
    cout<<"\n";
}
