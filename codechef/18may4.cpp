#include<bits/stdc++.h>

using namespace std;

int const M = 1e9+7;
int const lmt = 1e5+6;

long long fib[lmt];
int main(){
    int t; cin>>t;
    fib[2]=0;
    fib[3]=1;
    for(int i=4; i<lmt; i++){
        fib[i] = (fib[i-1]+fib[i-2])%M;
    }
    while(t--){
        int m,n;
        cin>>m>>n;
        long long a,ans,suma=0,sumb=0;

        for(int i=0; i<m; i++){
            cin>>a;
            suma = (suma + a%M)%M;
        }
        for(int i=0; i<m; i++){
            cin>>a;
            sumb = (sumb + a%M)%M;
        }

        ans = ((fib[n]*suma)%M + (fib[n+1]*sumb)%M) %M;
        ans = (ans*m)%M;
        if(n==1){
            ans = suma%M;
            ans = (ans*m)%M;
        }else if(n==2){
            ans = sumb%M;
            ans = (ans*m)%M;
        }
        cout<<ans<<"\n";
    }
}