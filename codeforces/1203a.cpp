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

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        
        for(int i=0; i<n; i++){
            cin>>a[i];
            a[i]--;
        }
        int ft = a[0];
        bool ok=true;
        for(int i=1; i<n; i++){
            if(a[i] != (ft+1)%n) {ok=false; break;}
            ft=a[i];
        }
        if(ok){
            cout<<"YES\n";
            continue;
        }
        ft=a[0];
        ok=true;
        for(int i=1; i<n; i++){
            if(a[i] != (ft-1+n)%n) {ok=false; break;}
            ft=a[i];
        }
        if(ok){
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
    
    
}


/*



*/