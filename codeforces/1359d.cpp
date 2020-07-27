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
int const lmt=1e5+5;
int a[lmt],l[lmt],r[lmt],pre[lmt],suf[lmt],ptree[4*lmt],stree[4*lmt];

int merge(int a, int b){
    int c = max(a,b);
    return c;
}

void pre_build(int node,int start, int end){
    if(start==end){
        ptree[node]=pre[start];
    }else{
        int mid = (start+end)/2;
        pre_build(2*node,start,mid);
        pre_build(2*node +1, mid+1, end);
        
        ptree[node]=merge(ptree[2*node],ptree[2*node+1]);
    }
}


int preq(int node, int start, int end, int l, int r){
    if(l>end || r<start) return -inf;
    else if(start>=l && end<=r){
        return ptree[node];
    }else{
        int mid = (start+end)/2;
        auto a =  preq(2*node,start,mid,l,r);
        auto b =  preq(2*node +1,mid+1,end,l,r);
        return merge(a,b);
    }
}

void suf_build(int node,int start, int end){
    if(start==end){
        stree[node]=suf[start];
    }else{
        int mid = (start+end)/2;
        suf_build(2*node,start,mid);
        suf_build(2*node +1, mid+1, end);
        
        stree[node]=merge(stree[2*node],stree[2*node+1]);
    }
}


int sufq(int node, int start, int end, int l, int r){
    if(l>end || r<start) return -inf;
    else if(start>=l && end<=r){
        return stree[node];
    }else{
        int mid = (start+end)/2;
        auto a =  sufq(2*node,start,mid,l,r);
        auto b =  sufq(2*node +1,mid+1,end,l,r);
        return merge(a,b);
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll n; cin>>n;
    stack<int> st;
    pre[0]=0;
    loop1(i,n){
    	cin>>a[i];
    	pre[i] = a[i] + pre[i-1]; 
    }
    suf[n+1]=0;
    for(int i=n; i>=0; i--) suf[i] = suf[i+1]+a[i];

    pre_build(1,1,n);
    suf_build(1,1,n);


    ll val=0;
    loop1(i,n){
    	if(!st.empty()){
    		while(!st.empty() && a[st.top()] <= a[i])st.pop();
    	}
    	if(st.empty())l[i] = 1;
    	else l[i] = st.top()+1;

    	st.push(i);

    	// pts(l[i]);
    }
    // pt("");

    while(!st.empty())st.pop();
    
    loop1(idx,n){
    	int i = n+1 - idx;

    	if(!st.empty()){
    		while(!st.empty() && a[st.top()] <= a[i])st.pop();
    	}

    	if(st.empty())r[i] = n;
    	else r[i] = st.top()-1;

    	st.push(i);
    }

    int ans=0;
    loop1(i,n){
        int val = preq(1,1,n,i,r[i])+ sufq(1,1,n,l[i],i);
        val -= (pre[i]+ suf[i]);
    	ans = max(ans,val);
    }
    pt(ans);
}


/*


*/



