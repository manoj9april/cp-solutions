#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k; cin>>n>>k;

    int a[n+1];
    int sum=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        if(i<=k) sum+= a[i];
    }
    int idx=1,ans=sum;
    for(int i=1; i+k<=n; i++){
        sum -= a[i];
        sum += a[k+i];

        if(sum<ans){
            ans=sum;
            idx=i+1;
        }
    }

    cout<<idx<<"\n";
}