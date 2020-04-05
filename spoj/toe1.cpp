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

struct node{
    int mat[3][3];
};

bool operator<(const node& t1, const node& t2) 
{ 
    return (t1.mat[0][0] < t2.mat[0][0]); 
}

map<node, int> vis;

bool ok;

bool done(int a[3][3]){

    loop(i,3){
        int sum=0;
        loop(j,3){
            sum += a[i][j];
        }
        if(abs(sum)==3) return true;
    }

    loop(j,3){
        int sum=0;
        loop(i,3){
            sum += a[i][j];
        }
        if(abs(sum)==3) return true;
    }
    loop(i,2){
        int sum=0;
        loop(j,3){
            sum += a[j][j + i*(j+2)%3];
        }
        if(abs(sum)==3) return true;
    }
    return false;
}

void dfs(node p, int val){
    if(ok)return;
    if(exist(vis,p) && vis[p]==2){
        ok = 1; return;
    }
    vis[p]=1;
    if(done(p.mat)) return;

    loop(i,3){
        loop(j,3){
            if(p.mat[i][j]==0){
                p.mat[i][j]=-val;
                if(!exist(vis,p) || vis[p]==2){
                    dfs(p, -val);
                }
                p.mat[i][j]=0;
            }
        }
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast
    string s;
    test{
        node a,b;
        loop(i,3){
            cin>>s;
            loop(j,3){
                int val;
                switch(s[j]){
                    case 'O': val=-1; break;
                    case 'X': val=1; break;
                    default : val=0;
                }
                a.mat[i][j] = val;
                b.mat[i][j]=0;
            }
        }

        ok=false;
        vis[a]=2;
        dfs(b,-1);
        
        cout<<(ok?"yes":"no")<<"\n";
    }
}


/*

// 



*/



