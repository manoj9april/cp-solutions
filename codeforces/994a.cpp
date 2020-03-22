#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    bool b[10];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int d;
    memset(b,false,sizeof b);

    for(int i=0; i<m; i++){
        cin>>d;
        b[d]=true;
    }
    for(int i=0; i<n; i++){
        if(b[a[i]]){
            cout<<a[i]<<" ";
        }
    }
    cout<<"\n";
}