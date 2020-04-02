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

    test{
        ll n,p,k;
        cin>>n>>p>>k;

        ll a[n+1],dp[n+1],money[n+1];
        for(int i=1; i<=n; i++) cin>>a[i];
        sort(a+1,a+n+1);
        dp[0]=0; money[0]=0; a[0]=0;
        ll pre=0;
        for(int i=1; i<=n; i++){
            pre += a[i];
            if(i<k){
                if(pre<=p){
                    dp[i]=i, money[i]=pre;

                }
                else {
                    dp[i]= dp[i-1];
                    money[i] = money[i-1];
                }
            }
            else{
                dp[i] = dp[i-1];
                money[i] = money[i-1];
                if(money[i-k] + a[i] <= p){
                    if(dp[i-1]< dp[i-k]+k){
                        dp[i] = dp[i-k]+k;
                        money[i] = money[i-k] + a[i];
                    }
                }
            }

            // pt(dp[i]);
        }

        pt(dp[n]);
    }
}


/*

// 

*/



