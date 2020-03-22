#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t; cin>>t;
    while(t--){

        long long n,k; cin>>n>>k;
        long long a[n];
        for(int i=0; i<n; i++) cin>>a[i];

        sort(a,a+n);
        long long val,cnt=0;
        for(int i=0; i<n-1; i++){
            val = k-a[i];
            int idx = lower_bound(a+i,a+n,val)-a;
            if(idx!=n && idx!=i && a[idx]==val) cnt++;
        }

        cout<<cnt<<endl;
    }
}