#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    sort(a,a+n);

    int val,ans=0;
    for(int i=0; i<n; i++){
        val = a[i];
        //cout<<"hi\n";
        int u = lower_bound(a,a+n,val)-a;
        if(n-u-1==val) {
            //cout<<i<<"\n";
            ans++;
        }

    }

    cout<<ans<<'\n';
}