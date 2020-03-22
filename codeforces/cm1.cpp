#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;
#define pt(x) cout<<x<<"\n";

#define mp make_pair
#define pb push_back
#define f first
#define s second


#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007


#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test   int t; cin>>t; while(t--)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef map<ll,ll> mll;
typedef set<ll> sl;


//////////////////////////////////////////////////////////////////////////////////////////
//                      CONSTANTS
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e5+5;

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////




int main(){
    string s,as="";
    ll k;
    cin>>s>>k;
    ll n = s.length();
    ll ta=0;
    for(int i=0; i<k; i++){
        vector<int> v;
        for(int j=i; j<n; j+=k){
            v.push_back(s[j]-'a');
        }
        ll ans = 1e16;
        int c = 0;
        for(int ch=0; ch<26; ch++){
            ll diff=0;
            for(auto it:v){
                ll dd = abs(it-ch);
                diff += min(26-dd,dd);
            }
            if(diff<ans){
                ans= diff;
                c = ch;
            }
        }
        //cout<<ans<<" ==== "<<char(c+'a')<<"\n";
        ta += ans;
        //as += (c+'a');
    }
    cout<<ta<<"\n";
    
}


/*



*/