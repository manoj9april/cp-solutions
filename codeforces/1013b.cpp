#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll n,x;
    cin>>n>>x;
    ll a[n];
    map<ll,int> occ;
    bool ok=false;
    int cnt=0;
    for(int i=0; i<n&& !ok; i++){
        cin>>a[i];
        if(occ[a[i]] && occ[a[i]]!=i+1){
            ok=true; 
        }
        occ[a[i]]=i+1;
    }
    for(int i=0; i<n && !ok; i++){
        if(occ[a[i]] && occ[a[i]]!=i+1){
            cnt=1; ok=true;
        }
        occ[a[i]&x]=i+1;
    }
    for(int i=0; i<n && !ok; i++){
        occ[a[i]&x]=0;
    }
    for(int i=n-1; i>=0 && !ok; i--){
        if(occ[a[i]] && occ[a[i]]!=i+1){
            cnt=1; ok=true;
        }
        occ[a[i]&x]=i+1;
    }
    for(int i=0; i<n && !ok; i++){
        if(occ[a[i]&x] && occ[a[i]&x]!=i+1){
            cnt=2; ok=true;
        }
    }
    cout<<(ok?cnt:-1)<<"\n";
}

