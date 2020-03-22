#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;

int main(){
    int t; cin>>t; ll g=1;

    while(t--){
        
        int n; cin>>n;
        ll a[n],dp[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        memset(dp,0,sizeof(dp));
        ll maxx=0,smaxx=0; int maxi=-1,smaxi=-1;
        int last=-1;
        if(n>0){
            dp[0] = a[0];
            maxx = dp[0]; maxi = 0;
            last=0;
        }else{
            cout<<"Case "<<g++<<": "<<0<<"\n"; continue;
        }
        
        
        for(int i=1; i<n; i++){
            if(a[i]==0){
                dp[i] = maxx; continue;
            }
            if(maxi == i-1){
                if(smaxx + a[i] > maxx){
                    dp[i] = smaxx + a[i];last=i;
                    smaxx=maxx ; smaxi = maxi;
                    maxx = dp[i]; maxi = i;
                }else{
                    dp[i] = maxx;
                }
            }else{
                dp[i] = maxx + a[i];
                smaxx=maxx ; smaxi = maxi;
                maxx = dp[i]; maxi = i;
                last =i;
            }
        }
        cout<<"Case "<<g++<<": "<<maxx<<"\n";
    }
}