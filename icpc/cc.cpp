#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define endd "\n"
#define fast ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define test int t;cin>>t;while(t--)
#define loop(i,n) for(int i=0;i<n;i++)
#define rloop(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,n) for(ll i=1;i<=n;i++)
#define RFOR(i,n) for(ll i=n;i>0;i--)
#define cloop(i,x,y) for(ll i=(x);i<=(y);++i)
#define bug(a) cout << #a << " = " << a << endl;
#define fbug(a, x, y) { cout << #a << ": "; cloop(i, x, y) cout << a[i] << ' '; cout << endl; }
#define sz size()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
#define setp(x) fixed<<setprecision(x)
#define pi 3.14159265358979323846264338
#define mset(x,t) memset(x,t,sizeof x);
#define spa cout<<endd
#define inf 1e18

ll power(ll a , ll b,ll modi)
{
    ll res = 1 ;
    while(b)
    {
        if(b%2) {
            res = (res * a) % modi ;
        }
        b/=2 ;
        a = (a*a) % modi ;
    }
    return res ;
}
int dirx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int diry[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

//*******************************TEMPLATE ENDS HERE *******************//

int main(){
    fast;
    test
    {
        
    }
}