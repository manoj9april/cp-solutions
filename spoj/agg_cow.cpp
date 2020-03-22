#include<bits/stdc++.h>

using namespace std;
int n,c;
int const lmt = 1e5+6;
int arr[lmt];

bool ispos(long long mid){
    int put=0;
    long long sum=0;
    int cnt=1;
    for(int i=1; i<n; i++){
        sum += 1LL*arr[i]-arr[i-1];
        if(sum>=mid) put=1;

        if(put){
            cnt++;
            sum=0;put=0;
        }

    }

    return (cnt>=c);
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>c;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);

        int mid,lo=0,hi=1e9+1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;

            if(ispos(mid)) lo = mid+1;
            else hi = mid-1;
        }

        cout<<hi<<"\n";
    }
}