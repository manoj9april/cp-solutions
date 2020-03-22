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

int a[300][300],b[300][300];

int main(){
    fast
    int T; cin>>T;
    for(int t=1; t<= T; t++)
    {
        ll r,c,k;
        cin>>r>>c>>k;
        
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>a[i][j];
                b[i][j]=1;
            }
        }
        
        for(int i=0; i<r; i++){
            for(int j=1; j<c; j++){
                if(a[i][j-1]==a[i][j]) b[i][j] += b[i][j-1];
            }
        }
        ll area=0,ans=0;
        ll prev=-1;
        for(int i=0; i<r; i++){
            for(int j=c-1; j>=0; j--){
                if(a[i][j]==prev) continue;
                area = b[i][j];
                ll mn=area;
                ll area1=0,area2=0;
                for(int k=i-1; k>=0; k--){
                    if(b[k][j]<mn) break;
                    area1 =  (i-k)*mn;
                }

                for(int k=i+1; k<r; k++){
                    if(b[k][j]<mn) break;
                    area2 =  (k-i)*mn;
                }
                ans = max(ans,area+area1+area2);
                prev=a[i][j];
            }
        }
        
        cout<<"Case #"<<t<<": "<<ans<<"\n";
    }
}


/*



*/