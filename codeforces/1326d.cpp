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

string s,ff,ee;
bool check(int i, int j){
    for(; i<j; i++,j--){
        if(s[i]!=s[j]) return false;
    }
    return true;
}

int kmp(string Z){
    int n = (int) Z.length();

    vector<int> F (n);

     F[0]=0;

    for (int i=1; i<n; ++i) {

        int j = F[i-1];

        while (j > 0 && Z[i] != Z[j])

            j = F[j-1];

        if (Z[i] == Z[j])  ++j;

        F[i] = j;

    }

    return F[n-1];
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    fast

    test{
        cin>>s;
        string ns="";
        int n = s.length();
        if(check(0,n-1)){
            cout<<s<<"\n";
            continue;
        }
        for(int i=0,j=n-1; i<j; i++,j--){
            if(s[i]!=s[j]){
                s = s.substr(i,j-i+1);
                break;
            }
            ns += s[i];
        }
        n = s.length();
        // char st=s[0],en=s[n-1];
        

        string r;
        reverse(all(s)); r = s;
        reverse(all(s));

        
        ll ans_st=kmp(s+'#'+ r);
        ll ans_en=kmp(r+'#'+s);
        
        reverse(all(s));
        cout<<ns;
        if(ans_en>ans_st){
            cout<<s.substr(0,ans_en);
        }else{
            reverse(all(s));
            cout<<s.substr(0,ans_st);
        }
        reverse(all(ns));
        cout<<ns<<"\n";
    }
    
}


/*

// 

for(int i=n-1; i>=0; i--){
            if(st==s[i]){
                if(check(0,i)){ans_st = i+1; break;}
            }
        }

        ll ans_en=0;
        reverse(all(s));
        for(int i=n-1; i>=0; i--){
            if(en==s[i]){
                if(check(0,i)){ans_en = i+1; break;}
            }
        }

*/