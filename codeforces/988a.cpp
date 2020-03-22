#include<bits/stdc++.h>

using namespace std;

#define ll long long

int a[101];
int main(){
    memset(a,-1,sizeof a);
    int n,k; cin>>n>>k;

    int val;
    for(int i=1; i<=n; i++){
        cin>>val;
        a[val]=i;
    }
    int cnt=0;
    for(int i=1; i<=100; i++){
        if(a[i]!=-1)cnt++;
    }
    if(cnt>=k){
        cout<<"YES\n";
        for(int i=1; i<=100; i++){
            if(k==0)break;
            if(a[i]!=-1){cout<<a[i]<<" ";k--;}
        }
        cout<<"\n";
    }else{
        cout<<"NO\n";
    }
}