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


ll manacher(int* d1, int* d2, string s){

    ll ans=0;
    int l=0,r=-1,n=s.length();
    int sum[n],good[n];
    for(int i=0; i<n; i++){

        int k = (i>r?1:min(d1[l+r-i], r-i+1));

        if(i>r){
            k=1;
            sum[i]=s[i]-'0';
            good[i]=1;
        }else{
            k = 
        }

        while(i-k>=0 && i+k<n && s[i-k]==s[i+k]) k++;

        d1[i]=k--;

        if(i+k>r){
            r = i+k;
            l = i-k;
        }
    }

    l=0,r=-1,n=s.length();
    for(int i=0; i<n; i++){

        int k = (i>r?0:min(d2[l+r-i+1], r-i+1));

        while(i-k-1>=0 && i+k<n && s[i-k-1]==s[i+k]) k++;

        d2[i]=k--;

        if(i+k>r){
            r = i+k;
            l = i-k-1;
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    string s; cin>>s;
    int n = s.length();
    int d1[n],d2[n];

    ll ans = manacher(d1,d2,s);
    pt(ans);
}


/*

// 



*/



