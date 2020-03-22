#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endd "\n"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define input freopen("inp.txt","r",stdin)
#define output freopen("out1.txt","w",stdout)
#define loop(i,n) for(ll i=0;i<n;i++)
#define rloop(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n) for(ll i=1;i<=n;i++)
#define RFOR(i,n) for(ll i=n;i>0;i--)
#define cloop(i,x,y) for(ll i=(x);i<=(y);++i)
#define bug(a) cout << #a << " = " << a << endl;
#define fbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }
#define sz size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define pi 3.14159265358979323846264338
#define mset(x) memset(x,0,sizeof x);
#define spa cout<<endd
#define com(x)#x
#define inf 2000
ll power(ll a , ll b,ll modi)
{
    ll res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % modi ;
        }
        b/=2 ;
        a = (a*a) % modi ;
    }
    return res ;
}
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dx[]={-1,0,1,0};
int dy[]={0,-1,0,1};

//*******************************TEMPLATE ENDS HERE *******************//
#define N 1000005 
ll ind[N],n,a[N],b[N],x,y;
vector<pii> vt;


int const lmt = 1e5+7;

int tree[4*lmt+1];

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
        //a[idx]=val;
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

int main()
{
    fast;
    test
    {
        int n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>x;
            a[i]=x;
        }
        for(int i=1; i<=n; i++)
        {
            cin>>y;
            b[i]=y;
            ind[b[i]]=i;
        }
        memset(tree,0,sizeof tree);
        ll ans=0;
        ll cnt1=0,cnt2=0;
        for(int i=1; i<=n; i++){
            int idx  = ind[a[i]];
            
            update(1,1,lmt,idx,1);
            ans += query(1,1,lmt,idx+1,lmt);
            //cout<<ans<<" ";
        }
        //cout<<endl;
        cout<<ans<<"\n";
    }
    return 0;
}