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



int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    int n; cin>>n;
    int path[n][n];
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        for(int j=0; j<n; j++){
            if(i==j)path[i][j]=0;
            else if(s[j]=='1') path[i][j] = 1;
            else{
                path[i][j]=200000;
            }
        }
    }

    int m; cin>>m;
    int gpath[m];
    for(int i=0; i<m; i++){
        cin>>gpath[i];
        gpath[i]--;
    }
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                path[i][j] = min(path[i][j] , path[i][k]+path[k][j]);
            }
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout<<path[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int take[m];
    for(int i=0; i<m; i++)take[i]=1;
    int ff=0,mm=1,lll=2;
    int cnt=m;
    while(lll<m){
        int first = gpath[ff];
        int mid = gpath[mm];
        int last = gpath[lll];
        // cout<<first<<' '<<mid<<" "<<last<<"===\n";
        if(path[first][last] >= path[first][mid]+path[mid][last]){
            take[mm]=0;
            cnt--;
        }else{
            ff=mm;
        }
        mm=lll;
        lll++;
    }
    cout<<cnt<<"\n";
    for(int i=0; i<m; i++){
        if(take[i]) cout<<gpath[i]+1<<" ";
    }
    cout<<"\n";
}


/*



*/