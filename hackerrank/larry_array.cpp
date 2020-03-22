#include <bits/stdc++.h>

using namespace std;

void rotate(int arr[], int p, int q){
    int temp=arr[p];
    arr[p] = arr[p+1];
    arr[p+1] = arr[q];
    arr[q] = temp;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        int p=0,q=2;
        while(q<n){
            while(arr[p]>arr[q]){
                rotate(arr,p,q);
            }
            p++; q++;
        }
        cout<<(arr[n-2]<arr[n-1]?"YES\n":"NO\n");
    }
}