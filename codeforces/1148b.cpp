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
    fast
    ll n,m,ta,tb,k;
    cin>>n>>m>>ta>>tb>>k;

    ll c;
    vpll v;
    ll i=0;
    for(i=0; i<n; i++) {cin>>c;v.push_back({c+ta,0});}
    for(i=0; i<m; i++) {cin>>c;v.push_back({c,1});}
    if(k>=m || k>=n){
        cout<<-1<<"\n";
        return 0;
    }
    sort(all(v));
    

    i=0;
    while(i<n+m && v[i].second == 1)i++;
    if(i==n+m){
        cout<<-1<<"\n";
        return 0;
    }
    // dbg(i);
    ll o,e;
    for(; k && i<n+m;){
        o=e=0;
        while(i<n+m && v[i].second == 0){
            i++;
            o++;
        }
        while(i<n+m && v[i].second == 1){
            i++;
            e++;
        }
        if(min(o,e) <= k){
            k -= min(o,e);
            // dbg(i);
            continue;
        }
        else {i -= (e); i+=k; k=0; break;}
    }
    // for(int k=0; k<n+m; k++)cout<<v[k].first<<" ";
    // cout<<"\n";
    // for(int k=0; k<n+m; k++)cout<<v[k].second<<" ";
    // cout<<"\n";
    // dbg(i);
    // dbg(k);

    if(i==n+m){
        cout<<-1<<"\n";
        return 0;
    }
    cout<<v[i].first+tb<<"\n";
    return 0;


    ll idx=-1;
    // i += k;
    for(; i<n+m; i++){
        if(v[i].second == 0){idx=i;break;}
    }
    if(idx==-1){
        cout<<-1<<"\n";
        return 0;
    }
    ll st=v[idx].first;
    ll nidx=-1;
    for(; i<=n+m; i++){
        if(v[i].second == 1 && v[i].first>=st){nidx=i;break;}
    }
    if(nidx==-1){
        cout<<-1<<"\n";
        return 0;
    }
    
    cout<<v[nidx].first+tb<<"\n";

}


/*



*/