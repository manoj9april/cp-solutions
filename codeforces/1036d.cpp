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

int const lmt=3e5+5;

ll a[lmt],b[lmt];

int main(){
    fast
    ll n,m;
    cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];

    cin>>m;
    for(int i=0; i<m; i++) cin>>b[i];

    /*
    int l=0,r=0;
    ll seg=0,cnt=0,sa,sb,flag=1;
    while(l<n && r<m){
        if(flag && a[l]==b[r]){l++;r++; seg++;}
        else{
            if(flag) {
                flag=0;
                sa=a[l];
                sb=b[r];
                if(a[l]<b[r])l++;
                else r++;
            }else{
                if(sa<sb){l++; sa += a[l];}
                else if(sb<sa){ r++; sb += b[r];}
                else {
                    flag=1;
                    l++; r++;
                    seg++;
                }
            }
        }
    }*/
    for(int i=1; i<n; i++) a[i] += a[i-1];
    for(int i=1; i<m; i++) b[i] += b[i-1];

    ll ans=0;
    for(int i=0; i<m; i++){
        if(binary_search(a,a+n,b[i]))ans++;
    }
    if(ans==0 || b[m-1]!=a[n-1])ans=-1;
    cout<<ans<<"\n";
}