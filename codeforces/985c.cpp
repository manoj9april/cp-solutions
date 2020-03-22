#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k,val;
    cin>>n>>k>>val;

    int a[n*k];
    for(int i=0; i<k*n; i++){
        cin>>a[i];
    }

    sort(a,a+n*k);

    int l=0,r;
    r = upper_bound(a,a+n*k,a[0]+val)-a-1;

    if(r<n-1){
        cout<<0<<"\n";
        return 0;
    }

    int cnt=0;
    long long ans=0;

    for(int i=0; i<=r; i+=k){
        ans += a[i];
        a[i]=-1;
        cnt++;
    }

    int j=r;
    while(cnt<n){
        if(a[j]!=-1){
            ans += a[j];
            a[j]=-1;
            cnt++;
        }
        j--;
    }

    cout<<ans<<"\n";
}