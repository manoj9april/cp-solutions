#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;cin>>n;

    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int k; cin>>k;
    multiset<int> ms(arr,arr+k-1);
    for(int i=0; i+k<n; i++){
        ms.insert(i+k-1);
        auto it = ms.end();it--;
        cout<<*it<<" ";
    }
}