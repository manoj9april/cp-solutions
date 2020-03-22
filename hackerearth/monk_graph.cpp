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

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

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

int const lmt=1e5+5;

int root[lmt];
int size[lmt];

int find(int i){
    if(root[i]!=i){
        return root[i]=find(root[i]);
    }

    return root[i];
}
int ans[lmt];

int main(){
    fast
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1; //cin>>t;
    while(t--){
        int n,m,a,b,x,y;
        cin>>n>>m;
        for(int i=1; i<=n; i++){
            size[i]=1;
            ans[i]=0;
            root[i]=i;
        }
        for(int i=0; i<m; i++){
            cin>>a>>b;
            x = find(a); y=find(b);
            if(x==y){
                ans[x]++;
            }else{
                if(size[x]<size[y]){ swap(x,y);}

                size[x]+=size[y];
                ans[x] += ans[y]; ans[x]++;
                root[y]=x;
                size[y]=0;ans[y]=0;
            }
        }
        int sum=0;
        for(int i=1; i<=n; i++){
            sum = max(sum,ans[i]);
        }
        cout<<sum<<"\n";
    }
}