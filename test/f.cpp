#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl;
#define pt(x) cout<<x<<"\n";

#define mp make_pair
#define pb push_back
#define f first
#define s second


#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007


#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define test   int t; cin>>t; while(t--)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;

typedef pair<ll, ll> pll;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pll> vpll;
typedef vector<vl> vvl;
typedef map<ll,ll> mll;
typedef set<ll> sl;


int const lmt = 1e5+1;
int n,m;
ll a[lmt],s[lmt],e[lmt], ptm[lmt], x[lmt],y[lmt];
int tree[4*lmt];

vpll ind;
vector<int,pii> rtm;


void build(int node,int start, int end){
    if(start==end){
        tree[node]=a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        // a[idx]=val;
        tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return INT_MAX;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return min(a,b);
    }
}



int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>s[i]>>e[i];
        rtm.pb({s[i],0,i});
        rtm.pb({e[i],1,i});
        cin>>a[i];
    }
    sort(all(rtm));
    cin>>m;
    build(1,1,n);
    for(int i=1; i<=m; i++){
        cin>>ptm[i]>>x[i]>>y[i];
        ind.pb({ptm[i],i});

    }

    sort(all(ind));

    int idx=0,lidx;
    ll ans[m+1];
    for(int i=0; i<m; i++){
        

        int opidx = ind[i].s;
        int oridx;

        while(rtm[lidx].f < ptm[opidx]){
            oridx = rtm[lidx].s.s;
            int val = rtm[lidx].s.f;
            if(val) break;
            update(1, 1,n, oridx,1e10);
            lidx++;
        }

        while(rtm[idx].f < ptm[opidx]){
            oridx = rtm[idx].s.s;
            int val = rtm[idx].s.f;
            if(val) break;
            update(1, 1,n, oridx,a[oridx]);
        }
        
        
        int res = query(1,1,n, max(1ll,x[opidx]-y[opidx]), min(n*1ll,x[opidx]+y[opidx]));
        ans[oidx]=res;
    }

    for(int i=1; i<=m; i++) cout<<ans[i]<<"\n";


}