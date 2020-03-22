#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    int a[n],b[n],c[n];
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i];
    }
    bool ok=true;
    c[0]=max(a[0],b[0]);
    for(int i=1; i<n; i++){
        if(min(a[i],b[i])>c[i-1]){
            ok=false;break;
        }
        c[i] = max(a[i],b[i])<=c[i-1]?max(a[i],b[i]):min(a[i],b[i]);
    }
    cout<<(ok?"YES":"NO")<<"\n";
}

