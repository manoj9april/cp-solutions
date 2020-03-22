#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+8;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s; cin>>s;
        ll ans=0;
        for(int i=1; i<n; i++){
            if(i<m){
                if(s[i]!=s[i-1]){
                    ans += 1LL*min(i,n-m);
                }
            }else{
                if(s[i]!=s[i-1]){
                    ans += 1LL*min(n-i,m);
                }
            }
        }
        cout<<ans<<"\n";
    }
}