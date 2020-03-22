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
#define what_is(x)  cerr << #x << " is " << x << endl;

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

int const lmt=2e5+5;

ll x1[lmt],ny1[lmt],x2[lmt],y2[lmt];
ll px1[lmt],pny1[lmt],px2[lmt],py2[lmt];
ll sx1[lmt],sny1[lmt],sx2[lmt],sy2[lmt];

int main(){
    fast
    ll n; cin>>n;
    loop(i,n){
        cin>>x1[i]>>ny1[i]>>x2[i]>>y2[i];
        if(i==0){
            px1[i]=x1[i]; pny1[i]=ny1[i]; px2[i]=x2[i]; py2[i]=y2[i];
        }else{
            px1[i]=max(px1[i-1],x1[i]);
            pny1[i]=max(pny1[i-1],ny1[i]);
            px2[i]=min(px2[i-1],x2[i]);
            py2[i]=min(py2[i-1],y2[i]);
        }
    }
    sx1[n-1]=x1[n-1]; sny1[n-1]=ny1[n-1]; sx2[n-1]=x2[n-1]; sy2[n-1]=y2[n-1];
    rev_rep(i,n-2,0,1){

        sx1[i]=max(sx1[i+1],x1[i]);
        sny1[i]=max(sny1[i+1],ny1[i]);
        sx2[i]=min(sx2[i+1],x2[i]);
        sy2[i]=min(sy2[i+1],y2[i]);
    }
    ll ax,ay;
    if(sx1[1]<=sx2[1] && sny1[1]<= sy2[1]){
        ax = (sx1[1]+sx2[1])/2;
        ay = (sny1[1]+sy2[1])/2;
    }else if(px1[n-2]<=px2[n-2] && pny1[n-2]<= py2[n-2]){
        ax = (px1[n-2]+px2[n-2])/2;
        ay = (pny1[n-2]+py2[n-2])/2;
    }else{
        rep(i,1,n-2,1){
            ll ix1,ix2,iny1,iy2;
            ix1=max(sx1[i+1],px1[i-1]);
            iny1=max(sny1[i+1],pny1[i-1]);
            ix2=min(sx2[i+1],px2[i-1]);
            iy2=min(sy2[i+1],py2[i-1]);
            if(ix1<=ix2 && iny1<= iy2){
                ax = (ix1+ix2)/2;
                ay = (iny1+iy2)/2;
            }
        }
    }
    cout<<ax<<" "<<ay<<"\n";
}