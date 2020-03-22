#include<bits/stdc++.h>

using namespace std;

int a[100];

int find(int beg,int end){
    if(beg>=end) return -1;
    if(beg+1==end){
        if(a[beg]>a[end]) return beg;
    }
    int mid = (beg+end)/2;
    int m1 = (beg + mid)/2;
    int m2 = (mid+1+end/2);
    if(m1<=m2){
        int i1 = find(beg,m1-1);
        if(i1!=-1) return i1;
         return find (m2+1,end);
    }else{
        return find(m1,m2);
    }

    return -1;
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int ans = find(0,n-1);

    cout<<ans<<"\n";
}