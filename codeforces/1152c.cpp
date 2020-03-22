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



//////////////////////////////////////////////////////////////////////////////////////////
//                      functions
//////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=4e4+1;
int pr[lmt];
vi prime;
void seive(){
    for(int i=2; i<=4e4; i++) pr[i]=i;

    for(int i=2; i<=4e4; i++){
        if(i==pr[i]){
            for(ll j=i+i; j<=4e4; j+=i)pr[j]=i;
            prime.push_back(i);
        }
    }
}

int main(){
    ll a,b;
    cin>>a>>b;
    ll aa=min(a,b);
    ll bb = max(a,b);
    a = aa; b=bb;
    ll diff=a-b;

    ll mx=1,k=0;
    ll rtn = sqrt(diff);
    for(ll i=2; i<=rtn; i++){
        if(diff%i==0){
            if(i>mx){
                mx=i;
                k = i * (a+i-1)/i  - a;
            }
            ll ii=i;
            i = diff/i;
            if(i>mx){
                mx=i;
                k = i * (a+i-1)/i  - a;
            }
            i=ii;
        }
    }

    cout<<k<<"\n";
}


/*



*/