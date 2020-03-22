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

int const lmt=1e5+5;

int n,m;
int a[lmt];
vector<int> tree[4*lmt];

void build(int node,int start, int end){
    if(end==start){
        tree[node].pb(a[start]);
        /*
        for(int i=start; i<=end; i++)tree[node].pb(a[i]);
        sort(tree[node].begin(),tree[node].end());
        */
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);

        // merge
        vi vv = tree[node*2 +1];
        vv.insert(vv.begin(),tree[2*node].begin(),tree[2*node].end());
        sort(vv.begin(),vv.end());
        int itr = vv.size()-1;
        if(vv.size()>3){
            while(vv[itr]-vv[itr-2]>=vv[itr-1] && itr>2) itr--;
            tree[node].assign(vv.begin()+itr-2, vv.end());
        }else{
            tree[node].assign(vv.begin(), vv.end());
        }
        
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        //cout<<"ggg\n";
        tree[node][0]=val;
        //cout<<"hhh\n";
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        

        //  merge
        vi vv = tree[node*2 +1];
        vv.insert(vv.begin(),tree[2*node].begin(),tree[2*node].end());
        sort(vv.begin(),vv.end());
        int itr = vv.size()-1;
        if(vv.size()>3){
            while(vv[itr]-vv[itr-2]>=vv[itr-1] && itr>2) itr--;
            tree[node].assign(vv.begin()+itr-2, vv.end());
        }else{
            tree[node].assign(vv.begin(), vv.end());
        }
    }
}

vi query(int node, int start, int end, int l, int r){
    if(l>end || r<start) {vi vv; vv.pb(-1); return vv; }
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        vi a =  query(2*node,start,mid,l,r);
        vi b =  query(2*node +1,mid+1,end,l,r);
        if(a[0]==-1) return b;
        else if(b[0]==-1) return a;

        vi vv = b;
        vv.insert(vv.begin(),a.begin(),a.end());
        sort(vv.begin(),vv.end());
        int itr = vv.size()-1;
        if(vv.size()>3){
            while(vv[itr]-vv[itr-2]>=vv[itr-1] && itr>2) itr--;
            vv.assign(vv.begin()+itr-2, vv.end());
        }else{
            vv.assign(vv.begin(), vv.end());
        }
        
        return vv;
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1; i<=m; i++){
        int q;int x,y;
        cin>>q>>x>>y;
        if(q==1){
            update(1,1,n,x,y);
        }else{
            
            vi vv = query(1,1,n,x,y);
            int it;
            for(it=vv.size()-1; it>=2; it--){
                if(vv[it]-vv[it-2]<vv[it-1])break;
            }
            if(it<2){
                cout<<0<<"\n";
            }else{
                cout<<1LL*vv[it]+vv[it-1]+vv[it-2]<<"\n";
            }
        }
    }
}



/*
5 4
3 1 8 9 7
2 1 5
1 2 12
2 1 3
2 2 5

*/