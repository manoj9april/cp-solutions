#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl
#define pt(x) cout<<x<<"\n"

#define mp make_pair
#define pb push_back
#define F first
#define S second


#define inf (int)1e9
#define infll 1e18
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


int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;

int d1[lmt], d2[lmt];
string s;

int kmp( string str){
    
    int len = str.length(), j=0;
    int f[len];
    f[0]=0;
    for(int i=1; i<len; i++){

        while(j>0 && str[i]!=str[j]){
            j = f[j-1];
        }
        
        if(str[i]==str[j])++j;
        f[i]=j;
    }
    return f[len-1];
}


int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("../input.txt", "r", stdin);
    // freopen("../output.txt", "w", stdout);
	// #endif
    fast

    while(cin>>s){
        string r = s;
        reverse(all(r));
        int idx = kmp(r+'#'+s);
        pt(s+r.substr(idx));
    }
}


/*

// 



*/



