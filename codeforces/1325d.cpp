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


int a[68][68];

bool put_one(int pos){
    bool done=false;
    for(int i=0; i<68; i++){
        if(a[i][pos]==0){
            done=true;
            a[i][pos]=1;
            break;
        } 
    }
    return done;
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    ll xr,sum; cin>>xr>>sum;
    if((xr+sum)%2){
        cout<<"-1\n";
        return 0;
    }
    ll ans=0,pre=0,c=0,pos=0;
    while(xr || sum){
        int x = xr%2;
        int s = sum%2;
        if(x==1 && s==0){
            put_one(pos);
            if(!c){
                put_one(pos-1);
                put_one(pos-1);
                c=1;
            }
        }else if(x==1 && s==1){
            put_one(pos);
            if(c){
                put_one(pos-1);
                put_one(pos-1);
            }
        }else if(x==0 && s==1){
            if(!c){
                put_one(pos-1);
                put_one(pos-1);
            }else{
                c=0;
            }
        }else{
            if(c){
                put_one(pos-1);
                put_one(pos-1);
            }
        }

        xr = xr/2;
        sum = sum/2;
        pos++;
    }

    

    int cnt=0;
    multiset<ll> st;
    // st.insert();
    // cout<<"========\n";
    for(int i=0; i<68; i++){
        ll val=0;
        for(int j=pos-1; j>=0; j--){
            val = 2*val + a[i][j];
            // cout<<a[i][j];
        }
        // cout<<"\n";
        if(!val)continue;
        st.insert(val);
    }
    // cout<<"======\n";
    if(c){
        cout<<"-1\n"; return 0;
    }
    ans = st.size();
    cout<<ans<<"\n";
    for(int ele : st){
        if(ele==0)continue;
        cout<<ele+LLONG_MAX<<" ";
    }
    cout<<"\n";
}


/*

// 

*/