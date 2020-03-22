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
    ll n,k;
    cin>>n>>k;
    int a[33]={0};
    int j=0,kk=0;
    while(n){
        if(n&1)a[j]=1,kk++;
        j++;
        n=n/2;
    }
    if(kk>k){
        cout<<"NO\n";
        return 0;
    }
    j--;
    k -= kk;
    while(k && j>0){
        while(j>0 && !a[j]) j--;
        while(j>0 && k && a[j]){
            a[j]--;
            a[j-1]+=2; k--;
        }
    }
    if(k){
        cout<<"NO\n";
        return 0;
    }else{
        cout<<"YES\n";
        ll res=1;
        for(int i=0; i<33; i++){
            while(a[i]){
                cout<<res<<" ";
                a[i]--;
            }
            res *= 2;
        }
    }
    cout<<"\n";
}


/*



*/