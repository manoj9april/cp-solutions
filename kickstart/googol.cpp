#include<bits/stdc++.h>

using namespace std;

long long be( long long n){
    long long a = 2;
    long long ans=1;
    while(n){
        if(n&1) ans = ans*a;

        a = a*a;
        n = n>>1;
    }

    return ans;
}

int solve(long long k){
    //cout<<k<<"***\n";
    double p = log2(k);
    if((long long)p==p) return 0;

    long long diff = k - be((long long)p);

    return (1-solve(k-2*diff));
}


int main(){
    freopen("googol.in","r",stdin);
    freopen("googol.out","w",stdout);
    int t; cin>>t;
    int tt=1;
    while(t--){
        long long k;
        cin>>k;

        cout<<"Case #"<<tt<<": "<<solve(k)<<"\n";

        tt++;
    }
    
}