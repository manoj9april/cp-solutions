#include<bits/stdc++.h>

using namespace std;
int const inf = 1e9+8;

int main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        int m;cin>>m;
        int b[m];
        for(int i=0; i<m; i++) cin>>b[i];
        sort(b,b+m);

        int ans = inf;
        int j;
        for(int i=0; i<n; i++){
            j = lower_bound(b,b+m,a[i])-b;
            if(j==m){
                ans = min(ans,abs(a[i]-b[j-1]));
            }else if(j==0){
                ans = min(ans,abs(a[i]-b[j]));
            }else{
                ans = min(ans,abs(a[i]-b[j-1]));
                ans = min(ans,abs(a[i]-b[j]));
            }
        }

        cout<<ans<<"\n";
    }
}