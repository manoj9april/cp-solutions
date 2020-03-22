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
    string s; cin>>s;
    int j=0;
    while(k){

        for(int i=0; k && i<n; i++){
            if(s[i]==char('a'+j)){
                s[i]='*';
                k--;
            }
        }
        j++;
    }

    for(int i=0; i<n; i++){
        if(s[i]!='*')cout<<s[i];
    }
    cout<<"\n";
}
