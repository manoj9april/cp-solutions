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

int const lmt=1e5 +5;

int pa[lmt];
int na[lmt];
int pcnt[lmt];
int ncnt[lmt];
int ptree[4*lmt];
int ntree[4*lmt];


void pupdate(int node, int start, int end, int idx, int val){
    if(start==end){
        pa[idx]=val;
        ptree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            pupdate(2*node,start,mid,idx,val);
        }else{
            pupdate(2*node +1,mid+1,end,idx,val);
        }
        
        ptree[node]=max(ptree[2*node],ptree[2*node+1]);
    }
}

int pquery(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return ptree[node];
    }else{
        int mid = (start+end)/2;
        int a =  pquery(2*node,start,mid,l,r);
        int b =  pquery(2*node +1,mid+1,end,l,r);
        return max(a,b);
    }
}

void nupdate(int node, int start, int end, int idx, int val){
    if(start==end){
        na[idx]=val;
        ntree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            nupdate(2*node,start,mid,idx,val);
        }else{
            nupdate(2*node +1,mid+1,end,idx,val);
        }
        
        ntree[node]=max(ntree[2*node],ntree[2*node+1]);
    }
}

int nquery(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return ntree[node];
    }else{
        int mid = (start+end)/2;
        int a =  nquery(2*node,start,mid,l,r);
        int b =  nquery(2*node +1,mid+1,end,l,r);
        return max(a,b);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1; //cin>>t;
    while(t--){
        int n; cin>>n;
        int ele,val;
        int dp[n+1];
        int mx=0;
        for(int i=1; i<=n; i++){
            cin>>ele;
            if(ele>0){
                val = 1+nquery(1,1,lmt,1,ele);
                pupdate(1,1,lmt,ele,val);
                pcnt[ele] = (pcnt[ele]+1)%MOD;
            }else{
                ele=-ele;
                val = 1+pquery(1,1,lmt,1,ele);
                nupdate(1,1,lmt,ele,val);
                ncnt[ele] = (ncnt[ele]+1)%MOD;
            }
            dp[i]=val;
            mx =max(mx,val);

        }

        ll ans=0;
        for(int i=1;i<=n; i++){
            /*
            if(na[i]==mx) ans = (ans+ncnt[i])%MOD;
            if(pa[i]==mx)ans = (ans+pcnt[i])%MOD;
            */
            if(dp[i]==mx) ans++;
        }
        cout<<mx<<" "<<ans<<"\n";
    }
}