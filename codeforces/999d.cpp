#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = (ll) 2e3 + 10 ;
const int INF = (ll) 1e9 ;
const int MOD = (ll) 1e9 + 7 ;
const int CHR = 97 ;
#define __Sync ios_base::sync_with_stdio(false) ; cin.tie(0) ; cout.tie(0) ;
#define __File freopen ( "input.txt" , "r" , stdin ) ; freopen ( "output.txt" , "w" , stdout ) ;
#define pb push_back
#define mp make_pair
#define X first
#define Y second

int const lmt= 2e5+4;
int cnt[lmt];
int arr[lmt];
int main(){
    __Sync
    int n,m;
    cin>>n>>m;
    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        arr[i]=a;
        cnt[a%m]++;
    }
    ll d=0,ans=0;
    int p = n/m;
    /*
    for(int i=0; i<m; i++){
        ans += d;
        d += (cnt[i]-p);
    }
    for(int i=0; d && i<m; i++){
        ans += d;
        d += (cnt[i]-p);
    }

    cout<<ans<<"\n";
    */
    ans=0;
    for(int i=0; i<n; i++){
        if(cnt[arr[i]%m]==p)continue;
        int f =arr[i]%m;
        if(cnt[f]>p){
            arr[i]++;
            cnt[f]--;
            cnt[(f+1)%m]++;
            ans++;
            i--;
        }
    }
    for(int i=0; i<n; i++){
        if(cnt[arr[i]%m]==p)continue;
        int f =arr[i]%m;
        if(cnt[f]>p){
            arr[i]--;
            cnt[f]--;
            cnt[(f-1+m)%m]++;
            ans++;
            i--;
        }
    }
    cout<<ans<<"\n";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}