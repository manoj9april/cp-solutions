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
typedef vector<long long int> vll;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

//////////////////////////////////////////////////////////

vll lt,rt;
ll a,b,cnt=0;

int lb(int target){
    int mid,lo=0,hi=rt.size()-1;

    while(lo<=hi){
        mid = lo+ (hi-lo)/2;
        if(target+rt[mid] <= b) lo =mid+1;
        else hi =mid-1;
    }
    return hi;
}

int ub(int target){
    int mid,lo=0,hi=rt.size()-1;

    while(lo<=hi){
        mid = lo+ (hi-lo)/2;
        if(target+rt[mid] >= a) hi = mid-1;
        else lo =mid+1;
    }
    return lo;
}

int main(){
    ll n;
    
    cin>>n>>a>>b;

    int u1 = n/2;
    int u2 = n-u1;
    ll left[u1],right[u2];
    for(int i=0; i<u1; i++){
        cin>>left[i];
    }
    for(int i=0; i<u2; i++){
        cin>>right[i];
    }

    
    for(ll num =0 ; num<(1<<u1); num++){
        ll sum=0;
        for(ll i=0; i<u1; i++){
            if(num & 1<<i){
                sum += 1LL*left[i];
            }
        }
        lt.pb(sum);
    }
    for(ll num=0; num<(1<<u2); num++){
        ll sum=0;
        for(ll i=0; i<u2; i++){
            if(num & 1<<i){
                sum += 1LL*right[i];
            }
        }
        rt.pb(sum);
    }

    sort(lt.begin(), lt.end());
    sort(rt.begin(), rt.end());

    int len = lt.size();
    for(int i=0; i<len; i++){
        int low = ub(lt[i]);
        int high = lb(lt[i]);
        if(high==-1 || low == rt.size()){
            continue;
        }else
            cnt += (high-low+1);
    }

    cout<<cnt<<"\n";
}