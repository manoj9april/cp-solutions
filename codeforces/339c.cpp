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

si st;

int main(){
    fast
    string s; cin>>s;
    ll m; cin>>m;

    loop(i,10){
        if(s[i]=='1') st.insert(i+1);
    }

    ll a=0,b=0;
    auto ele = st.begin();
    vi v;
    st.insert(-1);
    int last = -1;
    loop(i,m){
        if(i&1){
            a -= b; 
            st.erase(last);
            ele = st.lower_bound(a+1);
            st.insert(last);
            if(ele==st.end()){
                cout<<"NO\n";
                return 0;
            }
            b=*ele;
            last = b;
        }else{
            b-=a;
            st.erase(last);
            ele = st.lower_bound(b+1);
            st.insert(last);
            if(ele==st.end()){
                cout<<"NO\n";
                return 0;
            }
            a=*ele;
            last = a;
        }
        v.pb(*ele);
    }

    cout<<"YES\n";
    int sz = v.size();
    loop(i,sz){
        cout<<v[i]<<" ";
    }
    cout<<"\n";
    
}
