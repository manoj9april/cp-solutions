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


const int lmt=100001;

ll a[lmt];
ll tree[4*lmt+1];
ll lazy[4*lmt+1];

ll merge(ll l, ll r){
    return l+r;
}

void build(ll node, ll s, ll e){
    if(s==e){
        tree[node]=a[s];
        lazy[node]=0;
        return;
    }

    ll mid = (s+e)>>1;
    ll ln=(node<<1);
    ll rn = ln|1;
    build(ln, s, mid);
    build(rn, mid+1, e);

    tree[node] = merge(tree[ln],tree[rn]);
    lazy[node]=0;
}

void update(ll node, ll s, ll e, ll qs, ll qe, ll val){
    ll ln=(node<<1);
    ll rn = ln|1;

    if(lazy[node]!=0){
        tree[node] += (e-s+1)*lazy[node];
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
    }

    if(s>e || e<qs || qe<s){
        return;
    }

    if(qs<=s && e<=qe){
        lazy[node]+=val;
        tree[node] += (e-s+1)*lazy[node];
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
        return;
    }

    ll mid = (s+e)>>1;

    update(ln, s, mid,qs,qe,val);
    update(rn, mid+1, e, qs, qe, val);

    tree[node] = merge(tree[ln],tree[rn]);
}

ll query(ll node, ll s, ll e, ll qs, ll qe){
    ll ln=(node<<1);
    ll rn = ln|1;

    if(lazy[node]!=0){
        tree[node] += (e-s+1)*lazy[node];
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
    }

    if(s>e || e<qs || qe<s){
        return 0;
    }

    if(qs<=s && e<=qe){
        return tree[node];
    }

    ll mid = (s+e)>>1;

    ll left = query(ln, s, mid,qs,qe);
    ll right = query(rn, mid+1, e, qs, qe);

    return merge(left,right);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        ini(a,0);
        build(1,1,n);
        int qs,qe,val,type;
        rep(i,1,m,1){
            cin>>type>>qe;
            if(type==0){
                update(1,1,n,qe,n,-1);
            }else{
                int lo=1,hi=n,mid;
                while(lo<=hi){
                    mid = lo+(hi-lo)/2;
                    if(query(1,1,n,1,mid)>=qe) hi = mid-1;
                    else lo = mid+1;
                }
                cout<<(lo==n+1?-1:query(1,1,n,1,lo))<<"\n";
            }
        }
    }
}

