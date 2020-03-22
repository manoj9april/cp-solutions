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
    ll n; cin>>n;
    ll c,rs,re,ps,pe,bs,be;
    rs=re=ps=pe=bs=be=-1; 
    char ch;
    bool rss,bss,pss;
    rss=bss=pss=false;
    loop(i,n){
        cin >> c >> ch;
        if(ch=='R'){
            re=c;
            if(!rss){rs=c; rss=true;}
        }
        if(ch=='P'){
            pe=c;
            if(!pss){ps=c; pss=true;}
        }
        if(ch=='B'){
            be=c;
            if(!bss){bs=c; bss=true;}
        }
    }
    ll ans=0;
    if(rss && pss){
        rs = min(rs,ps);
        re = max(re,pe);
    }
    if(pss && bss){
        bs = min(bs,ps);
        be = max(be,pe);
    }
    if(rss && bss){
        ans = re-rs + be-bs;
        //if(pss) ans-=(pe-ps);
        //dbg(rs); dbg(re); dbg(bs); dbg(be); 
        //cout<<"hjh\n";
    }else if(bss && pss){
        ans = be-bs;
    }else if(rss && pss){
        ans = re-rs;
    }else if(rss){
        ans = re-rs;
    }else if(bss){
        ans = be-bs;
    }else if(pss){
        ans = pe-ps;
    }
    cout<<ans<<"\n";
}