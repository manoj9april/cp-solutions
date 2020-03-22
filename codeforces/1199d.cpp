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
int const lmt=2e5+5;


int vis[lmt];
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    int n; cin>>n;

    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];

    int q;cin>>q;

    int p[q],x[q],ty[q];
    for(int i=0; i<q; i++){
        cin>>ty[i];
        if(ty[i]==1){
            cin>>p[i]>>x[i];
            p[i]--;
        }else{
            cin>>x[i];
        }
    }

    int mx=0;
    for(int i=q-1; i>=0; i--){
        if(ty[i]==2) mx = max(mx,x[i]);
        else{
            int idx = p[i];
            if(!vis[idx]){
                a[idx]=max(x[i],mx);
                vis[idx]=1;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout<<(vis[i]?a[i]:max(a[i],mx))<<" ";
    }
    
}


/*



*/