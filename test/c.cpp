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


//////////////////////////////////////////////////////////////////////////////////////////
//                      main starts
//////////////////////////////////////////////////////////////////////////////////////////
int const lmt=1e5+5;

string s;
ll n;
ll ans[lmt];

struct Node{
    int a[26];
    Node* next[26];

    Node(){
        for(int i=0; i<26; i++)a[i]=0, next[i] = NULL;
    }
};


void dfs(Node* p, int idx){
    p->a[int(s[idx]-'a')] += 1;
    ll val = p->a[int(s[idx]-'a')];
    // dbg(idx);
    // dbg(val);
    ans[idx] = max(ans[idx], val);

    if(idx+1<n){
        if(p->next[int(s[idx]-'a')]) ;
        else {
            Node *c = new Node();
            p->next[int(s[idx]-'a')] = c;
        }

        dfs(p->next[int(s[idx]-'a')], idx+1);
    }
}


int main(){
    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
	#endif
    fast

    Node root;

    test{
        ll q; cin>>q;
        
        if(q==1){
            cin>>s;
            n = s.length();
            dfs(&root, 0);
            // cout<<"Got it\n";
        }else{
            ll idx;
            cin>>idx;
            cout<<ans[idx-1]<<"\n";
        }
    }
    
}


/*

// 

*/