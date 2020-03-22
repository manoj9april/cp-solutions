#include<bits/stdc++.h>

using namespace std;
#define ll long long
bool ck[1001];
int main(){
    int n; cin>>n;
    memset(ck,false,sizeof ck);
    int a[n];
    int cnt=n;
    for(int i=0; i<n; i++)cin>>a[i];
    for(int i=n-1; i>=0; i--){
        if(ck[a[i]]){a[i]=-1;cnt--;}
        ck[a[i]]=true;
    }
    cout<<cnt<<"\n";
    for(int i=0; i<n; i++){
        if(a[i]!=-1)cout<<a[i]<<" ";
    }
    cout<<"\n";
}