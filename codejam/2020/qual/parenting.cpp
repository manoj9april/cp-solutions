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
int const lmt=1e3+5;

int s[lmt],e[lmt];

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../../../input.txt", "r", stdin);
    freopen("../../../output.txt", "w", stdout);
	#endif
    fast
    int T=1;
    test{

        vector< pair< int , pii > > v;
        ll n; cin>>n;
        char act[n];
        loop(i,n){
            cin>>s[i]>>e[i];
            // ind[i]=i; 
            v.pb({s[i],{1,i}});
            v.pb({e[i],{0,i}});
        }
        sort(all(v));
        // sort(ind, ind+n, cmp);

        int ac=0,ok=1,c=0,j=0;
        loop(i,2*n){
            if(v[i].S.F == 1){ //start
                if(c==0){
                    act[ v[i].S.S ] = 'C';
                    c=1; 
                }else if(j==0){
                    act[ v[i].S.S ] = 'J';
                    j=1; 
                }
                ac++;
            }else{
                int idx = v[i].S.S;
                if(act[idx] == 'C') c=0;
                else j=0;
                ac--;
            }
            if(ac>2){
                ok=0; break;
            }
        }
        

        cout<< "Case #" << T++ << ": ";
        
        if(!ok) cout<<"IMPOSSIBLE";
        else{
            loop(i,n) cout<<act[i];
        }
        cout<<"\n";
    }
}


/*

// 



*/



