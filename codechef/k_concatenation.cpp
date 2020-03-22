#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n],b[2*n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            b[i]=b[i+n]=a[i];
        }
        long long sum=INT_MIN,best=INT_MIN;
        if(k==1){
            for(int i=0; i<n; i++){
                sum = (long long)max(a[i]+sum, (long long)a[i]);

                best = (long long)max(sum, best);
            }
            cout<<best<<endl;
        }else{
            long long tsum=0;
            int start=0, end=0,cstart=0;
            for(int i=0; i<2*n; i++){
                
                //sum = (long long)max(b[i]+sum, b[i]);
                tsum += b[i];
                if(b[i]>b[i]+sum){
                    cstart=i;
                    sum = (long long) b[i];
                }else{
                    sum = (long long) b[i]+sum;
                }

                if(sum>=best){
                    start=cstart;
                    end=i;
                    best = sum;
                }
                
                //best = (long long)max(sum, best);
            }
            tsum /= 2;
            if(tsum>0){
                if(!(start<n && end<n)){
                    best += (k-2)*tsum;
                }
            }
            cout<<best<<endl;
            
        }
    }
}