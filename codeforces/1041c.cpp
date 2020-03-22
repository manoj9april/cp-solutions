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

ll const lmt=2e5+5;

ll b[lmt],aa[lmt],a[lmt];
set<pii>  q;
int main(){
    fast
    ll n,m,d,diff;
    cin>>n>>m>>d;

    loop(i,n){
        cin>>a[i];
        q.insert({a[i],i});
    }
    int cnt=0;
    while(!q.empty()){
        cnt++;

        auto p = q.begin();
        ll val = p->f;
        ll pos = p->s;
        b[pos]=cnt;
        q.erase(p);

        while(1){
            p = q.lower_bound({val+d+1,0});
            if(p==q.end()) break;
            val = p->f;
            pos = p->s;
            b[pos]=cnt;
            q.erase(p);
        }
    }

    cout<<cnt<<"\n";
    loop(i,n){
        cout<<b[i]<<" ";
    }cout<<"\n";
}