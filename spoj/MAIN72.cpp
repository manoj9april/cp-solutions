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

bool taken[100001];
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        ini(taken,false);
        taken[0]=true;
        vi v;
        v.pb(0);
        int a,cnt=0;
        rep(i,1,n,1){
            cin>>a;
            int len = v.size();
            for(int j=0; j<len; j++){
                //cout<<(cnt++)<<" ";
                int ns = a + v[j];
                if(!taken[ns]){
                    
                    taken[ns]=true;
                    v.pb(ns);
                }
            }
        }

        ll sum=0;
        int len = v.size();
        rep(i,0,len-1, 1){
            sum += 1LL*v[i];
        }
        cout<<sum<<"\n";
    }
}