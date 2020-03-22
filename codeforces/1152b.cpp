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

vi v;

void itob(ll a){
    vi v;
    while(a){
        v.push_back(a&1);
        a >>= 1;
    }
    for(int i=v.size()-1; i>=0; i--) cout<<v[i];
    cout<<"\n";

}

bool ans;
ll pos;
vi vv;
ll a,cnt; 

void op1(){
    ll c=1;
    pos=0;
    ll aa=a;
    while(a){
        if(a&1);
        else pos=c;

        a >>= 1;
        c++;
    }
    a=aa;
    if(pos){
        vv.push_back(pos);
        cnt++;
        a ^= ((1ll<<pos)-1);
    }else{
        ans=1;
    }
}

void op2(){
    ll aa=a;
    while(a){
        if(a&1);
        else{
            cnt++;
            a=aa+1;
            return;
        }
        a >>= 1;
    }
    ans=true;
    a=aa;
}

int main(){
    fast
    cin>>a;
    
    cnt=0;
    ans=false;
    while(!ans){
        if(!ans) op1();
        if(!ans) op2();
    }

    cout<<cnt<<"\n";
    for(int i=0; i<vv.size(); i++) cout<<vv[i]<<" ";
    cout<<'\n';

}


/*



*/