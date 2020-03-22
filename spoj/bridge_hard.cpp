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

int const lmt=2*(1e6+5);

int a[lmt];
int tree[4*lmt];


void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        tree[node]=max(tree[2*node],tree[2*node+1]);
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
        return max(a,b);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        memset(a, 0, sizeof a);
        memset(tree, 0, sizeof tree);
        int n,m;
        cin>>n;
        m=n;
        pii p[n+1];
        for(int i=1; i<=n; i++) {cin>>p[i].f;  p[i].f += 1e6+1; }
        for(int i=1; i<=m; i++) {cin>>p[i].s;  p[i].s += 1e6+1; }

        sort(p+1,p+n+1);

        int dp[n+1]; int mx=0;
        for(int i=1; i<=n; i++){
            dp[i]=1;
            if(p[i].s!=1)
            dp[i] = 1+query(1,1,lmt,1,p[i].s);
            update(1,1,lmt,p[i].s,dp[i]);

            mx =max(mx,dp[i]);

            //cout<<i<<"  "<<query(1,1,lmt,1,p[i].s)<<"\n";
        }

        cout<<mx<<"\n";
    }
}