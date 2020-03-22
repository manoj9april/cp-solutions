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


int main(){
    fast
    ll n,a,b;
    cin>>n>>a>>b;
    string s; cin>>s;
    ll cnt=0;
    
    loop(i,n){
        if(s[i]=='.')cnt++;
    }
    
    ll val=0;
    vi v;
    ll odd=0,tl=0;
    loop(i,n){
        if(s[i]=='*'){
            if(val){
                if(val&1)odd++;
                v.pb(val);
                tl+=val/2;
                val=0;
            }
        }else val++;
    }
    if(val){
        if(val&1)odd++;
        v.pb(val);
        tl+=val/2;
        val=0;
    }
    ll aa=a,bb=b,sit;
    a -= tl;
    b -= tl;
    if(a<0)a=0;
    if(b<0)b=0;
    if(a>0){
        ll mn = min(a,odd);
        a -= mn;
        odd -= mn;
    }
    if(b>0){
        ll mn = min(b,odd);
        b -= mn;
        odd -= mn;
    }
    if(a<0)a=0;
    if(b<0)b=0;
    cout<<(aa+bb - a - b)<<"\n";

}



    /*
    for(int i = v.size()-1; i>=0; i--){
        dbg(v[i]);
    }
    dbg(a); dbg(b);
    
    for(int i = v.size()-1; i>=0; i--){
        if(a==0 && b==0)break;
        if(a>b){
            sit = (v[i]+1)/2;
            if(sit>=a){
                ans+=(a+b);
                break;
            }else{
                ans += sit+min(b,max(0ll,v[i]-a));
                a -= sit;
                b -= min(b,max(0ll,v[i]-a));
            }
        }else{
            sit = (v[i]+1)/2;
            if(sit>=b){
                ans+=(a+b);
                break;
            }else{
                swap(a,b);
                ans += sit+min(b,max(0ll,v[i]-a));
                a -= sit;
                b -= min(b,max(0ll,v[i]-a));
                swap(a,b);
            }
        }
        dbg(a); dbg(b);
    }

    cout<<min(cnt,ans)<<"\n";
    */