#include<bits/stdc++.h>
using namespace std;

int const lmt=1e5+4;
int a[lmt];

void rev(int i, int j){
    while(i<j){
        swap(a[i],a[j]);
        i++,j--;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        k = k%n;
        for(int i=0; i<n; i++)cin>>a[i];

        rev(0,n-k-1);
        rev(n-k,n-1);
        rev(0,n-1);
        for(int i=0; i<n; i++)cout<<a[i]<<" ";
        cout<<"\n";
    }
}