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
int const lmt=1e5+5;


int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    int T=1;
    test{
        string num1,num2;
        cin>>num1>> num2;
        int n1 = num1.length();
        int n2 = num2.length();
        reverse(all(num1));
        reverse(all(num2));
        int ans[n1+n2+5];
        ini(ans,0);
        int idx1=0,idx2=0,car=0;
        for(int i=0; i<n1; i++){

            int dig1=num1[i]-'0';
            
            for(int j=0,idx2=0; j<n2; j++,idx2++){
                int dig2 = num2[j]-'0';
                ll res = dig2*dig1 + ans[idx1+idx2]+car;
                car = res/10;
                ans[idx1+idx2] = res%10;
            }

            if(car){
                ans[idx1+idx2]+=car;
                // car = ans[idx1+idx2]/10;
                // ans[idx1+idx2] %=10;
                // idx2++;
            }
            idx1++;
        }
        cout<<"#"<<T++<<" ";
        // idx1--;
        for(int i=idx1+idx2; i>=0; i--)cout<<ans[i];
        cout<<"\n";

    }
}


/*

// 



*/



