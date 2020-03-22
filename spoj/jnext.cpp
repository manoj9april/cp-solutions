#include<bits/stdc++.h>

using namespace std;

void rearrange(int a[], int n, int idx){
    for(int i=n-1; i>idx; i--){
        if(a[i]>a[idx]){
            int temp;
            temp =a[i];
            a[i]=a[idx];
            a[idx]=temp;
            break;
        }
    }
    for(int i=idx+1,j=n-1; i<j; i++,j--){
        int temp;
        temp =a[i];
        a[i]=a[j];
        a[j]=temp;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int idx=-1;
        for(int i=n-2; i>=0; i--){
            if(a[i]<a[i+1]){
                idx = i;
                break;
            }
        }
        if(idx!=-1){
            rearrange(a,n,idx);
            for(int i=0; i<n; i++){
                cout<<a[i];
            }
            cout<<endl;
        }else{
            cout<<"-1\n";
        }
    }
}