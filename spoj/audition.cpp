#include<bits/stdc++.h>

using namespace std;


int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n+1];
        int pre[n+2];
        pre[0]=0;
        string s; cin>>s;
        for(int i=1; i<=n; i++){
            a[i]=s[i-1]-'0';
            pre[i]=pre[i-1]+a[i];
        }

        int cnt=0,lo,hi,mid;
        for(int i=1; i<=n; i++){
            if(k==0 && s[i-1]=='1') continue;
            lo=i; hi=n;
            while(lo<=hi){
                mid = (lo+hi)/2;
                if(pre[mid]-pre[i-1]<k)  lo=mid+1;
                else hi = mid-1;
            }
            int lb=lo;


            lo=i; hi=n;
            while(lo<=hi){
                mid = (lo+hi)/2;
                if(pre[mid]-pre[i-1]<=k)  lo=mid+1;
                else hi = mid-1;
            }
            int ub=hi;

            cnt += (ub-lb+1);
        }
        cout<<cnt<<"\n";
    }
}