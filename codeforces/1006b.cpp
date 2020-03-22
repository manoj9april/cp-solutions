#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int ck[2001];
int main(){
    int n,k; cin>>n>>k;
    int a[n],b[n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(b,b+n);
    ll ans=0;
    for(int i=0; i<k; i++){
        ck[b[n-1-i]]++;
        ans += b[n-1-i];
    }
    cout<<ans<<"\n";
    int last=-1;
    int tt=k-1;
    for(int i=0; i<n && tt; i++){
        while(!ck[a[i]])i++;
        ck[a[i]]--;
        cout<<(i-last)<<" ";
        last=i;
        tt--;
    }
    cout<<(n-1-last)<<"\n";
}

