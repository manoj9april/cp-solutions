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
    //si abc,ab,bc,ac,a,b,c;
    ll n,ele,len; cin>>n;
    ll mabc,mab,mac,mbc,ma,mb,mc,inf;
    mabc=mab=mac=mbc=ma=mb=mc=inf=1e7+2;
    string s;
    loop(i,n){
        cin>>ele>>s;
        sort(all(s));
        if(s=="ABC"){
            //abc.insert(ele);
            mabc=min(mabc,ele);
        }else if(s=="AB"){
            //ab.insert(ele);
            mab=min(mab,ele);
        }else if(s=="AC"){
            //ac.insert(ele);
            mac=min(mac,ele);
        }else if(s=="BC"){
            //bc.insert(ele);
            mbc=min(mbc,ele);
        }else if(s=="A"){
            //a.insert(ele);
            ma=min(ma,ele);
        }else if(s=="B"){
            mb=min(mb,ele);
        }else if(s=="C"){
            mc=min(mc,ele);
        }
    }
    ll ans=1e6+6,aa=0,bb=0,cc=0;
    
    if(mabc<inf)ans=min(ans,mabc);

    if(mab+mbc+mac<2*inf){
        ans = min(ans,mab+mac+mbc-max(mab,max(mac,mbc)));
    }
    if(ma+mb+mc<inf){
        ans = min(ans,ma+mb+mc);
    }
    if(mab<inf && mc<inf)ans = min(ans,mab+mc);
    if(mbc<inf && ma<inf)ans = min(ans,mbc+ma);
    if(mac<inf && mb<inf)ans = min(ans,mac+mb);
    if(ans==1e6+6){
        cout<<"-1\n"; return 0;
    }
    cout<<ans<<"\n";
}