#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    pair<int, int> a[n];
    for(int i=0; i<n; i++) { cin>>a[i].first; a[i].second=i+1; }

    sort(a,a+n);

    for(int i=0,j=n-1; i<j; i++,j--){
        cout<<a[i].second<<" "<<a[j].second<<"\n";
    }
}