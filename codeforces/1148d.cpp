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
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;


vector< pair<pll, ll> > v,p;

int main(){
    fast
    ll n,a,b; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a>>b;
        if(a<b)v.push_back({{a,b},i});
        else p.push_back({{a,b},i});
    }    

    if(v.size()>p.size()){
        sort(all(v));
        cout<<v.size()<<"\n";
        for(int i=v.size()-1; i>=0; i--){
            cout<<v[i].second+1<<" ";
        }
    }else{
        sort(all(p));
        cout<<p.size()<<"\n";
        for(int i=0; i<p.size(); i++){
            cout<<p[i].second+1<<" ";
        }
    }
    cout<<"\n";
}


/*



*/