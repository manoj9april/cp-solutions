#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        int a[n];
        ll cnt=0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            if(a[i]%m==0)cnt++;
        }
        
        cout<<(1<<cnt)-1<<"\n";
    }
}

