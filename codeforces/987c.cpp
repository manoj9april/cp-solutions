#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n; cin>>n;
    int s[n+1];
    int c[n+1];

    for(int i=1; i<=n; i++){
        cin>>s[i];
    }

    for(int i=1; i<=n; i++){
        cin>>c[i];
    }
    
    ll cost,cur,ans=1e9+8;
    for(int i=1; i<=n ;i++){
        cur = c[i];
        cost = 1e9+8;
        for(int j=1; j<i; j++){
            if(s[j]<s[i] && c[j]<cost){
                cost = c[j];
            }
        }
        cur += cost;
        cost = 1e9 + 8;
        for(int j=i+1; j<=n; j++){
            if(s[j]>s[i] && c[j]<cost){
                cost = c[j];
            }
        }
        cur += cost;

        ans = min(ans,cur);
    }

    cout<<(ans == 1e9+8?-1:ans)<<"\n";
}