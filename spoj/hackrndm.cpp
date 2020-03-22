#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k; 
    cin>>n>>k;
    int a[n];
    for(int i=0; i<n; i++) cin>>a[i];
    sort(a,a+n);

    int cnt=0;
    for(int i=0; i<n; i++){
        cnt += binary_search(a,a+n,a[i]+k);
        //if(p!=n) cnt++;
    }

    cout<<cnt<<"\n";
}