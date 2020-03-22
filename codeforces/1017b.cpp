#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string a,b;
    int n; cin>>n;
    cin>>a>>b;
    ll ans=0,z=0,k=0,p=0;
    for(int i=0; i<n; i++){
        if(a[i]=='0')z++;
    }
    for(int i=0; i<n; i++){
        if(b[i]=='1')continue;
        if(a[i]=='0'){ans += (n-z); k++;}
        else {ans += z; p++;}
    }
    ans -= (k*p);
    cout<<ans<<"\n";
}

