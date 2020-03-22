#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define scll(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define rloop(i,n) rev_rep(i,n-1,0,1)
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double pi=acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e6+5;

int rem[lmt];
int  a,b,n;

int be(ll n){
    ll a = 10,ans=1;
    while(n){
        if(n&1) ans = (ans*a)%b;

        a = (a*a)%b;
        n /= 2;
    }
    return ans;
}

int main(){
    fast
    string s; cin>>s;
    
    n = s.length();
    cin>>a>>b;
    rem[0]=(s[0]-'0')%a;
    for(int i=1; i<n; i++){
        rem[i] = (rem[i-1]*10 + (s[i]-'0'))%a;
    }
    int last = (s[n-1]-'0')%b;

    int cnt=1;
    for(int i=n-2; i>=0; i--){
        if(last==0 && rem[i]==0 && s[i+1]!='0'){
            cout<<"YES\n";
            cout<<(s.substr(0,i+1))<<"\n"<<(s.substr(i+1))<<"\n";
            return 0;
        }
        last = ((s[i]-'0')*be(cnt) + last)%b;
        cnt++;
    }

    cout<<"NO\n";
}