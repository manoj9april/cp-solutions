#include <bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int a[m];
    for(int i=0; i<m; i++){
        cin>>a[i];
    }

    sort(a,a+m);
    int diff=1000;
    for(int i=0,j=n-1; j<m; i++,j++){
        diff = min(diff,a[j]-a[i]);
    }

    cout<<diff<<"\n";
}