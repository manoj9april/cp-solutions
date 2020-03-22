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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1; //cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        k = k-n;
        ll val; ll ele,mul;
        multiset<pair<ll , pair<ll, int> > >  q;
        for(int i=0; i<n; i++){
            cin>>ele;
            q.insert(mp(ele,mp(ele,1)));
        }
        pair<ll , pair<ll, int> >  p;
        while(k--){
            p = *q.begin();
            p.s.s++; p.f = 1LL*p.s.f*p.s.s;

            q.erase(q.begin());
            q.insert(mp(p.f,mp(p.s.f,p.s.s)));
        }

        p = *q.begin();
        ll ans = p.f;
        cout<<ans<<"\n";
    }
}

