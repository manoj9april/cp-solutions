#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll last=0,n,m,nm,ans=0;
    cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>nm;
        ans =((last+nm)/m); 
        cout<<ans<<" ";
        last = (last+nm)%m;
    }
    cout<<"\n";
}

