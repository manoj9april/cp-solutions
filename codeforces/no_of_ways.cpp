#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n;
    cin>>n;
    int a[n];
    ll s=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        s += (ll)a[i];
    }
    if(s%3!=0){
        cout<<"0\n";
    }else{
        s /=3;
        int cnt[n]={0};
        ll ss=0;
        for(int i=n-1; i>=0; i--){
            ss += 1LL*a[i];
            if(ss==s){
                cnt[i]=1;
            }
        }
        for(int i=n-2; i>=0; i--) cnt[i] += cnt[i+1];

        ss=0;
        ll ans=0;
        for(int i=0; i<=n-3; i++){
            ss += a[i];
            if(ss==s){
                ans += cnt[i+2];
            }
        }

        cout<<ans<<"\n";
    }

}