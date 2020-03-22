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

int main(){
    int n,k; cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int cnt=0,l=0,r=n-1;
    while(l<n){
        if(a[l]>k)break;
        l++; cnt++;
    }
    while(l<r){
        if(a[r]>k)break;
        r--;cnt++;
    }

    cout<<cnt<<"\n";
}