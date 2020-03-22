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



const int lmt=1e5 +10;

struct nod{
    int zero,one,two;
};

nod tree[4*lmt+1];
int lazy[4*lmt+1];

void merge(nod &res,nod l, nod r){
    res.zero=l.zero+r.zero;
    res.one=l.one+r.one;
    res.two=l.two+r.two;
}

void build(int node, int s, int e){
    if(s==e){
        tree[node].zero=1;
        tree[node].one=0;
        tree[node].two=0;
        lazy[node]=0;
        return;
    }

    int mid = (s+e)>>1;
    int ln=node<<1;
    int rn = ln|1;
    build(ln, s, mid);
    build(rn, mid+1, e);

    //tree[node].pb(0);tree[node].pb(0);tree[node].pb(0);
    merge(tree[node], tree[ln],tree[rn]);
    lazy[node]=0;
}

void uplz(nod &res, int val){
    val %= 3;
    int a,b,c;
    a=res.zero; b =res.one; c=res.two;
    if(val==1){
        res.one = a;
        res.two = b;
        res.zero = c;
    }else if(val==2){
        res.two = a;
        res.zero = b;
        res.one = c;
    }
}

void update(int node, int s, int e, int qs, int qe, int val){
    int ln=node<<1;
    int rn = ln|1;

    if(lazy[node]){
        //tree[node] = (e-s+1)*lazy[node];
        uplz(tree[node],lazy[node]);
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
        //tree[node] = (e-s+1)*lazy[node];
        uplz(tree[node],lazy[node]);
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
        return;
    }

    int mid = (s+e)>>1;

    update(ln, s, mid,qs,qe,val);
    update(rn, mid+1, e, qs, qe, val);

    merge(tree[node], tree[ln],tree[rn]);
}

int query(int node, int s, int e, int qs, int qe){
    int ln=node<<1;
    int rn = ln|1;
    
    if(lazy[node]){
        //tree[node] = (e-s+1)*lazy[node];
        uplz(tree[node],lazy[node]);
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
        return tree[node].zero;
    }

    int mid = (s+e)>>1;

    int left = query(ln, s, mid,qs,qe);
    int right = query(rn, mid+1, e, qs, qe);

    return (left+right);
}

int main(){
    ios_base::sync_with_stdio(0);
    int t=1; //cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        build(1,1,n);
        int ty,x,y;
        while(q--){
            cin>>ty>>x>>y;
            x++; y++;
            if(ty==0){
                update(1,1,n,x,y,1);
            }else{
                cout<<query(1,1,n,x,y)<<"\n";
            }
        }
    }
}