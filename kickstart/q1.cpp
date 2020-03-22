#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+6;
ll arr[lmt];

int main(){
    //freopen("sample.in","r",stdin);
    //freopen("sample.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        ll n,m;
        cin>>n>>m;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            arr[i] = arr[n-1]-arr[i];
        }
        ll ans = 0;
        for(int i=0; i<m; i++){
            ans += arr[i]; 
        }
        if(m>0) ans -= m*arr[m-1];
        ll best = ans;
        for(int i=0; i<n-m; i++){
            ans =  ans - arr[i] + arr[i+m] + (arr[i+m-1]-arr[i+m])*m ;
            best = min(best,ans);
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout << best;
        //
        cout<<"\n";
    }
}
