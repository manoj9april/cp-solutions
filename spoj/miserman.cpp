#include<bits/stdc++.h>

using namespace std;

int a[101][101];

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    int val;
    for(int i=1; i<n; i++){
        for(int j=0; j<m; j++){
            val = a[i-1][j];
            if(j!=0){
                val = min(val,a[i-1][j-1]);
            }
            if(j!=m-1){
                val = min(val,a[i-1][j+1]);
            }
            a[i][j] += val;
        }
    }

    int ans = 1e9+8;
    for(int j=0; j<m; j++){
        ans = min(ans,a[n-1][j]);
    }
    cout<<ans<<"\n";
}