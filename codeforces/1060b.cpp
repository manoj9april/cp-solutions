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
    string s,a="",b=""; cin>>s;
    ll len = s.length();

    ll n = stoll(s);

    ll c=0,x,y,aa,bb;
    for(int i=len-1; i>=0; i--){
        aa=0; bb=((n%10)-c+10)%10;
        //dbg(aa); dbg(bb); dbg(c);
        for(x=0; x<=9; x++){
            for(y=0; y<=9; y++){
                if(( ((c+x+y)%10) == n%10) && (c+x+y)/10<=((n/10))){
                    if(x+y>aa+bb)aa = x ,bb=y;
                }
            }
        }
        c = (c+aa+bb)/10;
        n = n/10;
        a = char(aa+'0') + a;
        b = char(bb+'0') + b;
    }

    ll ans=0;
    for(int i=0; i<a.size(); i++){
        ans += (a[i]-'0'); 
    }
    for(int i=0; i<b.size(); i++){
        ans += (b[i]-'0'); 
    }
    dbg(a); dbg(b);
    cout<<ans<<"\n";
}