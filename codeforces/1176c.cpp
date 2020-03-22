#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
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



int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    
    ll n; cin>>n;

    mii mp;
    ll ele;
    int arr[6] = {4,8,15,16,23,42};

    vi a[6];
    ll pt[6]={0};
    mii pos;
    for(int i=0; i<6; i++)pos[arr[i]]=i;

    for(int i=0; i<n; i++){
        cin>>ele;
        a[pos[ele]].push_back(i);
    }
    ll ans=0,last=0,ok=1;
    for(int j=0; j<a[0].size(); j++){
        last = a[0][j];
        for(int i=1; i<6; i++){
            if(pt[i] >= a[i].size()){
                ok=0;break;
            }
            while(a[i][pt[i]]<last){
                pt[i]++;
                if(pt[i]>=a[i].size()){
                    ok=0;break;
                }
            }
            if(!ok)break;
            last = a[i][pt[i]];
        }
        if(!ok)break;
        ans++;
    }
    ans=n-6*ans;

    cout<<ans<<"\n";
}


/*



*/