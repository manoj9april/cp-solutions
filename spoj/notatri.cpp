#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    while(n){
        int c[n];
        for(int i=0; i<n; i++)cin>>c[i];

        sort(c,c+n);
        ll cnt=0;
        for(int i=0; i<n; i++)   // for b
        {
            for(int j=0; j<i; j++){
                int sum = c[i]+c[j];
                int lo = 0,hi=n-1;
                int mid;
                while(lo<=hi){
                    mid = (lo+hi)/2;
                    if(sum>=c[mid])lo=mid+1;
                    else hi = mid-1;
                }
                int upl = hi;
                /*
                int diff = c[i]-c[j];

                lo=0,hi=n-1;
                while(lo<=hi){
                    mid = (lo+hi)/2;
                    if(diff<=c[mid])hi=mid-1;
                    else lo = mid+1;
                }
                int lol = lo;
                */
                cnt += 1LL*(n-1-upl);
                //if(j<lol)cnt--;
            }
        }
        cout<<cnt<<"\n";
        cin>>n;
    }
}