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
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

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


const int lmt = 1e5 +1;
int a[lmt];
string p;

bool check(int i, int j){
    if(p[j]=='G' && a[i-1]<a[i]) return true;
    else if(p[j]=='L' && a[i-1]>a[i]) return true;
    else if(p[j]=='E' && a[i-1]==a[i]) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        for(int i=0; i<n; i++) cin>>a[i];

        cin>>p;
        int m = p.length();

        int f[n];
        f[0]=0;
        bool got =false;
        for(int i=1; i<n; i++){
            int j=f[i-1];
            
            while(j>0 && !check(i,j)){
                j = f[j-1];
            }
            
            if(check(i,j))++j;
            
            f[i]=j;
            if(j==m){
                cout<<"YES\n";
                got = true;
                break;
            }
        }

        if(!got){
            cout<<"NO\n";
        }
    }
}