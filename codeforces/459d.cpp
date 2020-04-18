#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " is " << x << endl
#define pt(x) cout<<x<<"\n"
#define pts(x) cout<<x<<" "

#define mp make_pair
#define pb push_back
#define F first
#define S second


#define inf (int)1e9
#define infll 1e18
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


int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e6+5;

int tree[4*lmt];


void update(int node, int start, int end, int idx, int val){
    if(start==end){
        tree[node]+=val;
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
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n; cin>>n;
    ll a[n];
    // mii occ;

    loop(i,n){
        cin>>a[i];
        // occ[a[i]]=1;
    }

    // int idx=1;
    // for(auto &c: occ){
    //     c.S = idx++;
    //     // dbg(c.F);
    //     // dbg(c.S);

    // }

    // loop(i,n){
    //     // dbg(a[i]);
    //     a[i]=occ[a[i]];
    //     // dbg(a[i]);
    // }

    // left to right
    mii fre,rfre;
    int lr[n],rl[n];
    loop(i,n){
        fre[a[i]]++;
        lr[i] = fre[a[i]];

        rfre[a[n-1-i]]++;
        rl[n-1-i] = rfre[a[n-1-i]];
        // pts(lr[i]);
    }
    // pt("");

    ll ans=0;
    for(int i=n-1; i>=0; i--){
        // pts(rl[n-1-i]);
        ans += query(1,1,lmt,0,lr[i]-1);

        update(1,1,lmt,rl[i],1);
    }
    // pt("");
    pt(ans);

}


/*

// 



*/



