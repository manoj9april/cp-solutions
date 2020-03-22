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
typedef pair<ll ,ll> pll;
//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e5+5;

ll sm(ll n){
    ll ans =0;
    while(n){
        ans += n%10;
        n = n/10;
    }
    return ans;
}
int main(){
    fast
    ll  t; cin>>t;
    while(t--){
        ll n,d;
        cin>>n>>d;
        //d = sm(d);
        //n = sm(n);
        queue<pll> q;
        ll v,p,val=n,pos=0;
        q.push({n,0});
        while(q.size()){
            v = q.front().f;
            p = q.front().s;
            q.pop();
            if(v<val){
                val = v;
                pos = p;
            }
            if(p>10) continue;
            q.push({sm(v),p+1});
            q.push({v+d,p+1});
        }
        cout << val <<" "<< pos <<"\n";
    }
}