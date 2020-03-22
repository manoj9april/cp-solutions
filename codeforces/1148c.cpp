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

int const lmt=3e5+5;

//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////


ll a[lmt];

int main(){
    fast
    
    ll n; cin>>n;
    ll i;
    for(i=0; i<n; i++){cin>>a[i]; a[i]--;}

    i=0;
    vi s,t;
    for(int i=0; i<n; i++){
        if(a[i]!=i){
            if(2*abs(a[i]-i) >= n) {
                s.push_back(i);
                t.push_back(a[i]);
                swap(a[i],a[a[i]]);
            }
            else{
                ll pos = a[i];
                swap(a[i],a[pos]);
                if(i<n/2 && pos<n/2){
                    s.push_back(i);
                    s.push_back(pos);
                    s.push_back(i);
                    t.push_back(n-1);
                    t.push_back(n-1);
                    t.push_back(n-1);
                }else if(i>=n/2 && pos >=n/2){
                    s.push_back(i);
                    s.push_back(pos);
                    s.push_back(i);
                    t.push_back(0);
                    t.push_back(0);
                    t.push_back(0);
                }else{
                    s.push_back(i); t.push_back(n-1);
                    s.push_back(0); t.push_back(n-1);
                    s.push_back(0); t.push_back(pos);
                    s.push_back(0); t.push_back(n-1);
                    s.push_back(i); t.push_back(n-1);
                }
            }
            i--;
        }
    }

    cout<<s.size()<<"\n";
    for(int i=0; i<s.size(); i++){
        cout<<s[i]+1<<" "<<t[i]+1<<"\n";
    }
}


/*



*/