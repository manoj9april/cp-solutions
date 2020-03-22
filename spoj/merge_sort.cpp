#include<bits/stdc++.h>

using namespace std;

long long int cnt;

void merge(int a[],int start, int end){
    int p=start;
    int mid = (start+end)/2;
    int q = mid+1;

    int arr[start-end +1];
    for(int i=start; i<=end; i++){
        if(p>mid){
            arr[i] = a[q++];
        }else if(q>end){
            arr[i] = a[p++];
            cnt++;
        }else if(a[p]<=a[q]){
             arr[i] = a[p++];           
        }else{
            arr[i] = a[q++];
            cnt++;
        }
    }
    for(int i=start; i<=end; i++) a[i]=arr[i];
}

void merge_sort(int a[], int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);

        merge(a,start,end);
    }
}

int main(){
    std::ios::sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n+1];
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        cnt=0;
        merge_sort(a,1,n);
        cout<<cnt<<endl;
    }
}