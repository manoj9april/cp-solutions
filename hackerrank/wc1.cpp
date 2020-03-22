#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    bool arr[n+1];

    memset(arr, false, sizeof arr);

    int a;
    for(int i=0; i<n; i++){
        cin>>a;
        arr[a]=true;
    }

    for(int i=1; i<=n; i++){
        if(!arr[i]){
            cout<<i<<" ";
        }
        
    }cout<<endl;
}