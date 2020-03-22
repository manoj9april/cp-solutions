#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    sort(a,a+n);
    cout<<(n%2==0?a[n/2-1]:a[n/2])<<"\n";
}