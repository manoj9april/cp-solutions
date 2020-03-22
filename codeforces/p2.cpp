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

int const lmt=200000+2;

int a[lmt];
int tree[4*lmt];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=0;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}



int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        pii b[n+1];
        b[0].f=b[0].s=0;
        for(int i=1; i<=n; i++){
            cin>>b[i].f;
            b[i].s=i;
        }

        sort(b+1, b+n+1);

        for(int i=1; i<=n; i++){
            a[b[i].s]=i;
        }

        build(1,1,lmt);
        ll ans =0;
        //rep(i,1,n,1) cout<<a[i]<<" ";
        //cout<<"\n";
        for(int i=n; i>0; i--){
            ans += 1LL*query(1,1,n,a[i],lmt);
            update(1,1,n,a[i],1);
        }

        cout<<ans<<"\n";
    }
}