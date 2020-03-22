#include<bits/stdc++.h>

using namespace std;
int const lmt = 1e5+4;
int neg[lmt],ans;

int main(){
    int t; cin>>t;
    while(t--){
        int n,a; cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a;
            neg[i]=neg[i-1]+(a==-1);
        }
        ans=n;
        for(int i=1; i<n; i++){
            ans = min(ans, i-neg[i] + neg[n]-neg[i]);
        }
        cout<<ans<<"\n";
    }
}