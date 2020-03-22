#include<bits/stdc++.h>

using namespace std;
#define ll long long
ll const m=1e9+7;

void mul(ll a[2][2],ll b[2][2]){
    ll c[2][2]={{0,0},{0,0}};
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            for(int k=0; k<2; k++){
                c[i][j] = (c[i][j]+ a[i][k]*b[k][j])%m; 
            }
        }
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            a[i][j]=c[i][j];
        }
    }
}
void pw(ll arr[2][2], ll n){
    ll ans[2][2]={{1,0},{0,1}};
    while(n){
        if(n&1) mul(ans,arr); //ans = ans*arr

        mul(arr,arr);
        n = n/2;
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            arr[i][j]=ans[i][j];
        }
    }
}


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll arr[2][2]={{1,1},{1,0}};
        pw(arr,n);
        cout<<((arr[0][0]+arr[0][1])%m)<<"\n";
    }
}