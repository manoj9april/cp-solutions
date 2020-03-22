#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int rtn = sqrt(n);

        long long sum=0;
        for(int i=2; i<=rtn; i++){
            if(n%i==0){
                sum += 1LL*(i + n/i);
            }
        }
        if(rtn*rtn==n) sum -= rtn;
        sum++;
        cout<<sum<<"\n";
    }
}