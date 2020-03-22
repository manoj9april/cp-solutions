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
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)

#define mp make_pair
#define pb push_back
#define f first
#define s second

#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007

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


int main(){
    int t; cin>>t;
    while(t--){
        vi v;
        string p,t,str;
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        t= "E";
        for(int i=1; i<n; i++){
            if(a[i]>a[i-1]) t+= 'G';
            else if(a[i]<a[i-1]) t+= 'L';
            else t+='E';
        }
        //cout<<t<<"\n";
        cin>>p;
        int m=p.length();
        str = p+'#'+t;
        
        int cnt=0;
        int len = str.length();
        int f[len];
        f[0]=0;

        bool  got =false;
        for(int i=1; i<len; i++){
            int j=f[i-1];
            
            while(j>0 && str[i]!=str[j]){
                j = f[j-1];
            }
            
            if(str[i]==str[j])++j;
            
            f[i]=j;
            if(j==m){
                cout<<"YES\n";
                got = true;
                break;
            }
        }
        if(!got){
            cout<<"NO\n";
        }
    }
}

