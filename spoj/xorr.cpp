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

int const lmt=1000000+5;

int xa[33],la[33],ra[33],aa[33];

void inif(){
    for(int i=0; i<33; i++)xa[i]=la[i]=ra[i]=aa[i]=0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t,x,l,r,j; cin>>t;
    while(t--){
        inif();
        cin>>x>>l>>r;
        j=0;
        ll xx = x;
        while(x){
            if(x&1)xa[j]=1;
            x=x/2; j++;
        }
        j=0;
        while(l){
            if(l&1)la[j]=1;
            l=l/2; j++;
        }
        j=0;
        while(r){
            if(r&1)ra[j]=1;
            r=r/2; j++;
        }


        ll lv=0,rv=0,xv=0;
        for(j=32; j>=0; j--){
            lv= 2*lv; rv = 2*rv; xv = 2*xv;
            if(la[j])lv++; 
            if(ra[j])rv++;

            if(xa[j]==0){
                if(xv+1>=lv && xv+1<=rv) { aa[j]=1; xv++;}
            }else{
                if(xv>=lv && xv<=rv) { aa[j]=0;}
                else {aa[j]=1; xv++;}
            }
        }
        /*
        for(int j=5; j>=0; j--)cout<<ra[j]<<" ";
        cout<<endl;
        for(int j=5; j>=0; j--)cout<<la[j]<<" ";
        cout<<endl;
        for(int j=5; j>=0; j--)cout<<aa[j]<<" ";
        cout<<endl;
        */

        ll ans=0,val=1;
        for(j=0; j<33; j++){
            if(aa[j])ans += val;
            val = val*2;
        }
        ans  = (ans^xx);
        cout<<ans<<"\n";
    }
}