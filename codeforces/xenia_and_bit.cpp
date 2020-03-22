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

const int lmt = (1<<17) +1;
int a[lmt];
int tree[4*lmt];

bool build(int node, int s, int e){
    if(s==e){
        tree[node]=a[s];
        return true;
    }
    int mid  = (s+e)>>1;

    bool aur = build(node<<1, s, mid);
    build((node<<1) +1, mid+1, e);

    if(aur){
        tree[node] =  tree[node<<1] | tree[(node<<1) +1];
        return false;
    }
    else{
        tree[node] =  tree[node<<1] ^ tree[(node<<1) +1];
        return true;
    }
    

}

bool update(int node, int s, int e, int idx, int val){
    if(s==e){
        tree[node] = a[idx] = val;
        return true;
    }
    int mid = (s+e)>>1;

    bool aur;
    if(idx<=mid){
        aur = update(node<<1, s, mid, idx, val);
    }else{
        aur=update((node<<1) +1, mid+1, e, idx, val);
    }

    if(aur){
        tree[node] =  tree[node<<1] | tree[(node<<1) +1];
        return false;
    }
    else{
        tree[node] =  tree[node<<1] ^ tree[(node<<1) +1];
        return true;
    }
}

int main(){
    int n,m;
    cin>>n>>m;

    rep(i,1,1<<n,1){
        cin>>a[i];
    }

    int idx,val;
    build(1,1,1<<n);
    //cout<<tree[1]<<"\n";
    rep(i,1,m,1){
        cin>>idx>>val;
        update(1,1,1<<n,idx,val);
        cout<<tree[1]<<"\n";
    }
}