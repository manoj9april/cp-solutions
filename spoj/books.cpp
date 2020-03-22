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

vi v;
vector<long long> ps;
int n,k;
ll mx;
bool check(ll mid){
    ll pg=0;
    int pre=0,next;
    //typeof(ps.begin()) it;
    for(int i=0; true ; i++){
        if(i>=k) return true;
        if(pre==n) return false;
        /* if(pg>=mx) return false;
        it = lower_bound(ps.begin(), ps.end(), pg+mid);
        next = it-ps.begin();
        if(it==ps.end()) next--;
        */
        pg=0;
        while(pg<=mid && pre<n){
            pg += v[pre++];
        }
        /*
        for(int j=pre; j<=next; j++){
            pg += v[j];
        }
        pre = next+1;
        */
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        
        cin>>n>>k;
        v.clear();
        ps.clear();
        int bk;
        ll lo=0,hi=0;
        for(int i=0 ; i<n; i++){
            cin>>bk;  v.pb(bk);
            hi+=bk;
        }
        mx=hi;
        sort(v.begin(), v.end());
        ll sum=0;
        /*
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        cout<<"-----\n";
        */
        for(int i=0; i<n; i++){
            sum+=v[i];
            ps.pb(sum);
        }

        ll mid;
        while(lo<=hi){
            mid = (lo+hi)/2;
            if(check(mid)) lo = mid+1;
            else hi = mid-1;
        }
        hi++;
        //cout<<mx<<" "<<hi<<"\n";
        ll pg=0;
        int pre=0,next;
        //typeof(ps.begin()) it;
        for(int i=0; i<k ; i++){
            /* if(pg>=mx) return false;
            it = lower_bound(ps.begin(), ps.end(), pg+mid);
            next = it-ps.begin();
            if(it==ps.end()) next--;
            */
            pg=0;
            while(pg<=hi && pre<n){
                
                pg += v[pre++];
                if(pg<=hi){
                    cout<<v[pre-1]<<" ";
                }
            }
            cout<<"/ ";
            /*
            for(int j=pre; j<=next; j++){
                pg += v[j];
            }
            pre = next+1;
            */
        }
        cout<<"\n";
    }
}