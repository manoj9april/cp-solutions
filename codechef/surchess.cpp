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
#define loop(k,t) rep(k,0,t-1,1)
#define rev_rep(idx, from, to, dec) for (int idx=from ; i>=to ; idx-=dec)
#define rloop(i,n) rev_rep(i,n-1,0,1)
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

int const lmt=2e2+2;

//int dp[lmt][lmt][lmt];
int a[lmt][lmt],b[lmt][lmt],c[lmt][lmt];

unordered_map<ll, ll> mpp;

int main(){
    fast
    ll n,m;
    cin>>n>>m;
    string s;
    loop(i,n){
        cin>>s;
        //dbg(i);
        for(int j=0; j<m; j++){
            //dbg(j);
            a[i][j] = (s[j]-'0');
            if((i+j)%2 == 0){
                b[i][j] = (a[i][j]!=0);
                c[i][j] = (a[i][j]==0);
            }else{
                b[i][j] = (a[i][j]==0);
                c[i][j] = (a[i][j]!=0);
            }
        }
    }
    for(int i=1; i<n; i++){
        b[i][0] += b[i-1][0];
        c[i][0] += c[i-1][0];
    }
    for(int j=1; j<m; j++){
        b[0][j] += b[0][j-1];
        c[0][j] += c[0][j-1];
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<m; j++){
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
            c[i][j] += c[i-1][j] + c[i][j-1] - c[i-1][j-1];
        }
    }
    ll bv,cv;
    loop(i,n){
        for(int j=0; j<m; j++){
            ll ans=0;
            for(ll k=0; k+i<n && k+j <m; k++){
                ll nx = k+i;
                ll ny = k+j;
                if(i==0 && j==0){
                    bv = b[nx][ny];
                    cv = c[nx][ny];
                }else if(i==0){
                    bv = b[nx][ny] - b[nx][j-1];
                    cv = c[nx][ny] - c[nx][j-1];
                }else if(j==0){
                    bv = b[nx][ny] - b[i-1][ny];
                    cv = c[nx][ny] - c[i-1][ny];
                }else{
                    bv = b[nx][ny] - b[i-1][ny] - b[nx][j-1] + b[i-1][j-1];
                    cv = c[nx][ny] - c[i-1][ny] - c[nx][j-1] + c[i-1][j-1];
                }

                mpp[bv] = max(mpp[bv],k+1);
                mpp[cv] = max(mpp[cv],k+1);
            }
        }
    }

    for(int i=1; i<=n*m; i++){
        mpp[i] = max(mpp[i],mpp[i-1]);
    }

    ll q,ele; cin>>q;
    while(q--){
        cin>>ele;
        if(ele>n*m) ele = n*m;
        cout<<mpp[ele]<<"\n";
    }
}

/*
8 8
00101010

*/