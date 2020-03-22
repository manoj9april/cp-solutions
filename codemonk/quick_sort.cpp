#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+3;
int a[lmt];

int par(int beg, int end){
    int piv=beg;
    int i=beg+1;
    for(int j=beg+1; j<=end; j++){
        if(a[j]<a[piv]){
            swap(a[j],a[i]);
            i++;
        }
    }
    swap(a[i-1],a[piv]);
    return i-1;
}

void qs(int beg,int end){
    if(beg<end){
        int piv = par(beg,end);
        qs(beg,piv-1);
        qs(piv+1,end);
    }
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++)cin>>a[i];
    qs(0,n-1);
    for(int i=0; i<n; i++)cout<<a[i]<<" ";
    cout<<"\n";
}