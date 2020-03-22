#include<bits/stdc++.h>

using namespace std;
const int lmt=100002;
int arr[lmt];
int k;
int lb(int lo, int hi){
    int mid;
    while(lo<hi){
        mid = lo + (hi-lo +1 )/2;
        if(arr[mid]<=k) lo = mid;
        else hi = mid-1;
    }
    return lo+1;
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    sort(arr, arr+n);

    int q; cin>>q;
    while(q--){
        cin>>k;
        if(k<arr[0]) { cout<<"0\n"; continue; }
        cout<<lb(0,n-1)<<"\n";    
    }
    
}