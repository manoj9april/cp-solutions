#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int a[105];
int main(){
    int n,m,l,r;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>l>>r;
        a[l]++;
        a[r+1]--;
    }
    int cnt=0;
    for(int i=1; i<=m; i++){
        a[i] += a[i-1];
        if(a[i]==0)cnt++;
    }
    cout<<cnt<<"\n";
    for(int i=1; i<=m; i++){
        if(a[i]==0)cout<<i<<" ";
    }cout<<"\n";
}

