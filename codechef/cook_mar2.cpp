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

int const lmt=1000000+5;
ll r,c;

bool exist(ll x,ll y){
    if(x>=0 && x<r && y>=0 && y<c) return true;
    return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        
        cin>>r>>c;
        ll arr[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>arr[i][j];
            }
        }
        bool nosol = false;
        for(int i=0; i<r; i++){
            if(nosol) break;
            for(int j=0; j<c; j++){
                if(arr[i][j]==-1){
                    if(!exist(i-1,j) && !exist(i,j-1)) arr[i][j]=1;
                    else if(!exist(i-1,j)) arr[i][j]=arr[i][j-1];
                    else if(!exist(i,j-1)) arr[i][j]=arr[i-1][j];
                    else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
                }else{
                    if(!exist(i-1,j) && !exist(i,j-1)){ int g=1;}
                    else if(!exist(i-1,j)) {if(arr[i][j]<arr[i][j-1]){nosol = true; break;}}
                    else if(!exist(i,j-1)){ if(arr[i][j]<arr[i-1][j]){nosol = true; break;}}
                    else if(arr[i][j]<max(arr[i-1][j],arr[i][j-1])) {nosol = true; break;}
                }
            }
        }

        if(nosol){
            cout<<"-1\n";
        }else{
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    cout<<arr[i][j]<<" ";
                }cout<<"\n";
            }
        }
    }
}