#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0; i<n; i++)cin>>a[i];
    int pre=1,cnt=1;
    for(int i=1; i<n; i++){
        if(a[i]==1){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
    for(int i=1; i<n; i++){
        if(a[i]==1){
            cout<<pre<<" ";
        }
        pre=a[i];
    }
    cout<<pre<<"\n";
}

