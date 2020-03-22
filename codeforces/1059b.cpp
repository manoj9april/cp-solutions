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

int const lmt=1e3+5;
int kx[8]={-1,-1,0,1,1,1,0,-1};
int ky[8]={0,-1,-1,-1,0,1,1,1};

string s[lmt],dp[lmt];
ll n,m;
int vis[1005][1005];

void check(int i, int j)
{
    if(i==0 || j==0 || i==n-1 || j==m-1)return;
    for(int k=0; k<8; k++){
        int nx = i+kx[k];
        int ny = j+ky[k];
        dp[nx][ny]='#';
    }
}

void modify(int i, int j)
{
    for(int k=0; k<8; k++){
        int nx = i+kx[k];
        int ny = j+ky[k];
        vis[nx][ny]=true;
    }
}

int main()
{
    ll n,m;
    cin>>n>>m;
    loop(i,n){
        cin>>s[i];
        dp[i]="";
        for(int j=0; j<m; j++)dp[i] +='.';
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(s[i][j]==dp[i][j]) continue;

            if(s[i][j]=='.'){
                cout<<"NO\n";
                return 0;
            }else{
                check(i+1,j+1);
            }
        }
    }

    cout<<"YES\n";
}
