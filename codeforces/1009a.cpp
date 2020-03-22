#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n,m; cin>>n>>m;
    int c[n],a[m];
    for(int i=0; i<n ;i++){
        cin>>c[i];
    }
    for(int i=0; i<m ;i++){
        cin>>a[i];
    }
    int st=0;
    int cnt=0;
    for(int i=0; i<n; i++){
        while(st<m && a[st]==-1)st++;
        if(st<m && a[st]>=c[i]){
            a[st]=-1;
            cnt++;
            st++;
        }
    }
    cout<<cnt<<"\n";
}

