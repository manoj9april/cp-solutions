#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    cout<<setprecision(15)<<fixed;
    int n,a,b;
    cin>>n>>a>>b;
    int arr[n];
    for(int i=0; i<n; i++)cin>>arr[i];
    sort(arr,arr+n);
    int j=min(a,b);
    int k=n-1;
    long double ans,sa=0,sb=0;
    while(j){
        sa += arr[k];
        k--;j--;
    }
    j = max(a,b);
    while(j){
        sb += arr[k];
        k--;j--;
    }
    ans = (sa/min(a,b)+sb/max(a,b));
    cout<<ans<<"\n";
}

