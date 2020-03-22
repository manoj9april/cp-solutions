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

const int lmt = 3*(1e4) +10;
int a[lmt];
int key;
vi tree[4*lmt];

int res[lmt];
void merge(int e1,int e2,vi &lt, vi &rt, vi &res){
    int p=0,q=0;
    while(p<=e1 || q<=e2){
        if(p>e1) res.pb(rt[q++]);
        else if(q>e2) res.pb(lt[p++]);
        else if(lt[p]<rt[q]) res.pb(lt[p++]);
        else if(lt[p]>=rt[q]) res.pb(rt[q++]);
    }
}
void build(int node,int start, int end){
    if(start==end){
        tree[node].pb(a[start]);
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        int e1 = tree[2*node].end()-tree[2*node].begin();
        int e2 = tree[2*node+1].end()-tree[2*node+1].begin();
        merge(e1-1,e2-1,tree[2*node],tree[2*node+1], tree[node]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return (tree[node].end() - upper_bound(tree[node].begin(),tree[node].end(),key));
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}


int main(){
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];
        build(1,1,n);
        int m; cin>>m;
        int ans=0; int i,j;
        while(m--){
            
            
            cin>>i>>j>>key;
            i = (i^ans);
            j = (j^ans);
            key = (key^ans);
            //cout<<"i:"<<i<<" j:"<<j<<" key:"<<key<<"\n";
            if(i<1) i=1;
            if(j>n) j=n;
            if(i>j) ans = 0;
            else{
                
                ans = query(1,1,n,i,j);
            }
            cout<<ans<<"\n";
        }
    }
}