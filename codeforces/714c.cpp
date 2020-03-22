#include<bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define sci(t) scanf("%d",&t)
#define scll(t) scanf("%lld",&t)
#define scc(t) scanf("%c",&t)
#define scs(t) scanf("%s",t)
#define scf(t) scanf("%f",&t)
#define sclf(t) scanf("%lf",&t)
#define ini(arr, val) memset(arr, (val), sizeof(arr))
#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define all(a)      (a).begin(),(a).end()
#define exist(s,e)  (s.find(e)!=s.end())
#define dbg(x)  cerr << #x << " is " << x << endl;

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define inf (int)1e9
#define eps 1e-9
#define PI 3.1415926535897932384626433832795
#define mod 1000000007

#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

const double pi=acos(-1.0);

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef map<int,int> mii;
typedef set<int> si;
typedef multiset<int> mulsi;
typedef unsigned long int uli;
typedef long long int ll;
typedef unsigned long long int  ull;

//////////////////////////////////////////////////////////////////////////////////////////
/*                                
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
*/                              
//////////////////////////////////////////////////////////////////////////////////////////

int const lmt=1e5+5;

map<string, int> occ;

int main(){
    fast
    ll q,n; cin>>q;
    string s,str;
    char ch;

    while(q--){
        cin>>ch;
        if(ch=='?'){
            cin>>s;
            str=s;
            ll ans=0;
            while(str.length()<=19){
                ans += occ[str];
                str = '0'+str;
            }
            str=s;
            int len = s.length();
            int i=0;
            while(str[i]=='0'){
                if(len-i <= 19){
                    ans += occ[str.substr(i,len-i)];
                }i++;
            }
            if(len-i <= 19){
                ans += occ[str.substr(i,len-i)];
            }
            ans -= occ[s];

            cout<<ans<<"\n";
        }
        else{
            cin>>n;
            s = to_string(n);
            str="";
            int len = s.length();
            loop(i,len){
                if((s[i]-'0')%2==0)str += '0';
                else str += '1';
            }
            if(ch=='+') occ[str]++;
            else occ[str]--;
        }
    }
}