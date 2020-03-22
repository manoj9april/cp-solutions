#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), szof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl;
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


int a[lmt][65];

void biget(ll ele, ll i){
    int j=0;
    while(ele){
        if(ele&1)a[i][j]=1;
        j++;
        ele = ele/2;
    }
}

int root[lmt],sz[lmt];

ll find(int i){
    if(i!=root[i])
        root[i] = find(root[i]);

    return root[i];
}

bool unn(ll a,ll b){
    int x = find(a);
    int y = find(b);

    if(x!=y){
        root[x]=y;
        sz[y]+=sz[x];
        return false;
    }else{
        return true;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    int n; cin>>n;
    ll ele;
    for(int i=0; i<n; i++){
        cin>>ele;
        root[i]=i;
        sz[i]=1;
        biget(ele,i);
    }
    for(int i=0; i<65; i++){
        int cnt=0;
        for(int nd=0; nd<n; nd++){
            if(a[nd][i]){
                cnt++;
            }
        }
        if(cnt>2){
            cout<<3<<"\n";
            return 0;
        }
    }
    bool ok=false;
    ll ans=1e8+7;
    for(int i=0; i<65; i++){
        vi v;
        for(int nd=0; nd<n; nd++){
            if(a[nd][i]){
                v.pb(nd);
            }
        }
        
        for(int j=1; j<v.size(); j++){
            if(unn(v[0],v[j])){
                ok=true;
                // cout<<"hgdj";
                ans = min(ans,1ll*sz[find(v[j])]);
                // return 0;

            }
        }
        
    }
    cout<<(ok?ans:-1)<<"\n";
    
}


/*



*/