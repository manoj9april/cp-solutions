#include<bits/stdc++.h>

typedef long long ll;

using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        ll n,r;
        cin>>n>>r;
        r = r>n-r?n-r:r;
        ll ans =1;
        for(int i=1; i<=r; i++,n--){
            if(n%i==0)ans *= n/i;
            else if(ans%i==0) ans = ans/i*n;
            else ans = ans*n/i;
        }

        cout<<ans<<endl;
    }
}