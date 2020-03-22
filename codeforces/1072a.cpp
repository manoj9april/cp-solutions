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

int const lmt=1e6+5;

bool ck[lmt];

int main(){
    fast
    ll a,b,sp=0; cin>>a>>b;
    if(b<a){swap(a,b); sp=1;}
    ini(ck,false);
    ll sa=0;
    ll last=0;
    for(int i=1; sa+i<=a; i++){
        ck[i]=true;
        sa+=i;
        last=i-1;
    }
    ll j=1;
    while(j*(j-1)/2 <= (a+b)) j++;
    j--;
    if(a-sa){
        //cout<<"jhdsk\n";
        
        ll df = a-sa;
        while(last+df>j && last>0) last--;

        ck[last]=false;
        ck[last+df]=true;
    }
    vi aa,bb;
    if(sp){
        for(int i=1; i<=j; i++){
            if(ck[i])bb.pb(i);
        }
    }else{
        for(int i=1; i<=j; i++){
            if(ck[i])aa.pb(i);
        }
    }
    ll sb=0;
    if(sp){
        ll k=1;
        while(sb+k<=b){
            if(!ck[k]){ aa.pb(k); sb+=k;}
            k++;
        }
    }else{
        ll k=1;
        while(sb+k<=b){
            if(!ck[k]) {bb.pb(k); sb+=k;}
            k++;
        }
    }

    cout<<aa.size()<<"\n";
    for(int i=0; i<aa.size(); i++){
        cout<<aa[i]<<" ";
    }
    cout<<"\n";

    cout<<bb.size()<<"\n";
    for(int i=0; i<bb.size(); i++){
        cout<<bb[i]<<" ";
    }
    cout<<"\n";
}
