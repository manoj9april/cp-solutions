#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n;  cin>>n;
        int arr[n][n];

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>arr[i][j];
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += arr[i][i];
        }

        for(int j=1; j<n; j++){
            int x=0,y=j;
            int sum=0;
            while(x<n && y<n){
                sum += arr[x][y];
                x++; y++;
            }

            ans = max(ans,sum);
        }

        for(int j=1; j<n; j++){
            int y=0,x=j;
            int sum=0;
            while(x<n && y<n){
                sum += arr[x][y];
                x++; y++;
            }

            ans = max(ans,sum);
        }

        cout<<ans<<"\n";
    }
}