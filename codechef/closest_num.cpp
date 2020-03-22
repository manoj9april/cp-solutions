#include<bits/stdc++.h>

using namespace std;

long long ppow(long long a, long long b){
    if(b==0) return 1;
    long long u = ppow(a,b/2);
    if(b%2==0) return(u*u);
    else return (a*u*u);
}

int main(){
    int t=1; cin>>t;
    while(t--){
        //cout<<"\n";
        long long a,b,x; cin>>a>>b>>x;
        //cout<<ppow(2,4);
        if(b<0 && a!=1){
            cout<<0<<"\n";
            continue;
        }
        long long ab = ppow(a,b);
        if(x>ab){
            cout<<0<<"\n";
        }
        else{
            cout<<(ab-(ab%x))<<"\n";
        }

    }
}