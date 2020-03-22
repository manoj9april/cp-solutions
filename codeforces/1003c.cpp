#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 5001;
ll a[lmt];
int main(){
    cout<<setprecision(15)<<fixed;
    int n,k; cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        a[i]+= a[i-1];
    }
    long double ans=0.0,kk=k;
    while(k<=n){
        kk=k;
        for(int i=1; i+k-1<=n; i++){
            ans = max(ans,(a[i+k-1]-a[i-1])/kk);
        }
        k++;
    }

    cout<<ans<<"\n";
}