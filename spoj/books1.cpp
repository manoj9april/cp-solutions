#include<bits/stdc++.h>

using namespace std;
#define ll long long

int a[501]; 
int n,k;

bool ispos(ll pg){
    ll kk=k;
    ll p=0;
    int i;
    for(i=0; kk && i<n; i++){
        p += 1LL*a[i];
        if(p>pg){
            kk--;
            p=0;
            i--;
        }
    }
    return (i==n);
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=0; i<n; i++)cin>>a[i];
        ll lo=1,hi=1LL*10000000*500,mid;
        while(lo<=hi){
            mid  = lo+(hi-lo)/2;
            if(ispos(mid))hi=mid-1;
            else lo=mid+1;
        }
        
        ll p=0;
        for(int i=0; i<n; i++){
            p += 1LL*a[i];
            if(p>lo){
                cout<<"/ ";
                i--;
                p=0;
            }else{
                cout<<a[i]<<" ";
            }
        }
        cout<<"\n";
    }

    
}