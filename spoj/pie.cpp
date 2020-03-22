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
//#define PI 3.1415926535897932384626433832795
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

int const lmt=1e5+1;
long double PI=3.1415926535897932384626433832795;
long double vol[lmt];
ll n,f;

ll check(long double vl){
    ll cnt=0;
    for(int i=0; i<n; i++){
        cnt += floor(vol[i]/vl);
    }

    return cnt;
}

int main(){
    int t; cin>>t;
    cout<<setprecision(4)<<fixed;
    while(t--){
        
        cin>>n>>f;f++;
        long double r,hi=0;
        for(int i=0; i<n; i++){
            cin>>r;
            vol[i] = 1.0*PI*r*r;
            hi += vol[i];
        }

        long double mid,lo=PI/f;

        int itr=50;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check(mid)>=f)lo=mid;
            else hi = mid;
        }

        cout<<mid<<"\n";
    }
}