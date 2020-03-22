#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int occ[101];
int n,m,b;
bool ck(int mid){
    int val=0;
    for(int i=1; i<=100; i++){
        val += (occ[i]/mid);
    }
    return (val>=n);
}
int main(){
    cin>>n>>m;
    for(int i=0; i<m; i++){
        cin>>b;
        occ[b]++;
    }
    if(n>m){
        cout<<0<<"\n";
        return 0;
    }
    int lo=1,hi=100,mid;
    while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(ck(mid))lo = mid+1;
        else hi = mid-1;
    }
    cout<<hi<<"\n";
}

