#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define loop(i,n)  for(ll i=0; i<n; i++)
#define loop1(i,n)  for(ll i=1; i<=n; i++)

#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cout << #x << " = " << x << endl
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



//===========================DEBUG======================//
#define XOX 1
vector<string> vec_splitter(string s) {
	s += ',';
	vector<string> res;
	while(!s.empty()) {
		res.push_back(s.substr(0, s.find(',')));
		s = s.substr(s.find(',') + 1);
	}
	return res;
}
void debug_out(
vector<string> __attribute__ ((unused)) args,
__attribute__ ((unused)) int idx, 
__attribute__ ((unused)) int LINE_NUM) { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(vector<string> args, int idx, int LINE_NUM, Head H, Tail... T) {
	if(idx > 0) cerr << ", "; else cerr << "Line(" << LINE_NUM << ") ";
	stringstream ss; ss << H;
	cerr << args[idx] << " = " << ss.str();
	debug_out(args, idx + 1, LINE_NUM, T...);
}
#ifdef XOX
#define debug(...) debug_out(vec_splitter(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#else
#define debug(...) 42
#endif

//================================================================//



//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e6+2;
int const mm = 2ll*pow(2ll,ceil(log2(1e6+2)) );
ll n;
int Tree[mm];
int a[lmt];

void update(int idx, ll x)
{
	// Let, n is the number of elements and our queries are
	// of the form query(n)-query(l-1), i.e range queries
	// Then, we should never put N or MAX in place of n here.
	while(idx<=n)
	{
		Tree[idx]+=x;
		idx+=(idx&-idx);
	}
}

ll query(int idx)
{
	ll sum=0;
	while(idx>0)
	{
		sum+=Tree[idx];
		idx-=(idx&-idx);
	}
	return sum;
}


// int merge(int a, int b){
// 	return (a+b);
// }
// void build(int node,int start, int end){
//     if(start==end){
//         tree[node]=a[start];
//     }else{
//         int mid = (start+end)/2;
//         build(2*node,start,mid);
//         build(2*node +1, mid+1, end);
        
//         tree[node]=merge(tree[2*node],tree[2*node+1]);
//     }
// }

// void update(int node, int start, int end, int idx, int val){
//     if(start==end){
//         a[idx]+=val;
//         tree[node]+=val;
//     }
//     else{
//         int mid = (start+end)/2;
//         if(idx>=start  && idx<=mid){
//             update(2*node,start,mid,idx,val);
//         }else{
//             update(2*node +1,mid+1,end,idx,val);
//         }
        
//         tree[node]=merge(tree[2*node],tree[2*node+1]);
//     }
// }

// int query(int node, int start, int end, int l, int r){
//     if(l>end || r<start) return 0;
//     else if(start>=l && end<=r){
//         return tree[node];
//     }else{
//         int mid = (start+end)/2;
//         auto a =  query(2*node,start,mid,l,r);
//         auto b =  query(2*node +1,mid+1,end,l,r);
//         return merge(a,b);
//     }
// }
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    int q,ele; cin>>n>>q;
    loop(i,n){
    	cin>>ele;
    	update(ele,1);
    	a[ele]++;
    }
    // build(1,1,n);

    while(q--){
    	cin>>ele;
    	if(ele<0){
    		ele = -ele;
    		int lo=1,hi=n, mid;
    		while(lo<=hi){
    			mid = lo+ (hi-lo)/2;
    			if(query(mid)>= ele)hi=mid-1;
    			else lo = mid+1;
    		}
    		update(lo,-1);
    		a[lo]--;
    	}else{
    		update(ele,1);
    		a[ele]++;
    	}
    }

    loop1(i,n){
    	if(a[i]){
    		pt(i);
    		return 0;
    	}
    }
    pt(0);
}


/*


*/



