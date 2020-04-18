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
int const lmt=1e5+5;

ll n,m;
ll a[lmt];

const int M = 1e6+3;
int spf[M];
//spf[6] = 2 and not 3
void pre()
{
	int i;
	spf[1] = 1; spf[2] = 2;
	loop(i, M) spf[i] = i;
	for(i=2; i<M; i++){
		if (spf[i] != i) continue;
		for(int j = 2*i; j<M; j+=i){
			if (spf[j] == j)
				spf[j] = i;
		}
	}
}

void cal_pow(ll* f, ll num){
    if(num==0) return;
    while(num!=1){
        int pr = spf[num];
        ll cnt=1;
        while(spf[num]==spf[num/spf[num]]){
            num = num/spf[num];
            cnt++;
        }
        f[pr] = max(f[pr], cnt);
        num = num/spf[num];
    }
}

ll be(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1) ans *= a;
        a *= a;
        n = n/2;
    }
    return ans;
}

ll cal_gcd(ll* f_lcm, ll num){
    ll ans=1;
    // if(num==0) return ;
    while(num!=1){
        int pr = spf[num];
        ll cnt=1;
        while(spf[num]==spf[num/spf[num]]){
            num = num/spf[num];
            cnt++;
        }
        ans *= be(pr,min(f_lcm[pr], cnt));
        num = num/spf[num];
    }
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    pre();

    test{
        cin>>n>>m;
        ll f_lcm[m+1];
        ini(f_lcm,0);

        loop(i,n){
            cin>>a[i];
            cal_pow(f_lcm, a[i]);
        }

        // ll f_m[m+1];
        ll mx = 0, best=0;
        for(int i=1; i<=m; i++){
            // ini(f_m,0);
            // cal_pow(f_m, i);
            ll g = cal_gcd(f_lcm, i);
            if(mx < i/g){
                best = i;
                mx = i/g;

                // dbg(best);
                // dbg(mx);
                // dbg(i);
                // dbg(g);
                // pt("=======");
            }
        }
        pt(best);
    }
}


/*

// 



*/



