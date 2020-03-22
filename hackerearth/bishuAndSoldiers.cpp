#include<bits/stdc++.h>


using namespace std;

int bs(int target, int a[], int start, int end){
    while(start<end){
        int mid = start+(end-start)/2;
        if(target==a[mid]) return mid;
        else if(target<a[mid]) end = mid-1;
        else start = mid;
    }
    return start;
}

int main(){
    int n;
    cin>>n;
    int a[n],pre[n];int sum=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0; i<n; i++){
        sum = pre[i] = sum + a[i];
    }
    int m; cin>>m;
    for(int i=0; i<m; i++){
        int target; cin>>target;
        int ans = bs(target,a,0,n-1);
        cout<<ans+1<<" "<<pre[ans]<<endl;
    }
}