#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int ele;
        int arr[4]={0};
        for(int i=0; i<n; i++){
            cin>>ele;
            arr[ele%4]++;
        }
        int ans=0;
        ans += arr[2]/2;
        arr[2] %= 2;
        ans += (arr[1]>arr[3]?arr[3]:arr[1]);
        arr[1] = abs(arr[1]-arr[3]);
        if(arr[2]%2==1){
            if(arr[1]>=2){
                ans += 2;
                arr[1] -= 2;
                arr[2]=0;
            }
        }
        if(arr[1]>=4){
            ans += 3*(arr[1]/4);
            arr[1] %= 4;
        }
        if(arr[1]!=0 || arr[2] !=0 ){
            cout<<"-1\n";
        }else{
            cout<<ans<<endl;
        }

    }
}