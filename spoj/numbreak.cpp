#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+1;

int spf[lmt];

void pre(){

    for(int i=1; i<lmt; i++){
        spf[i]=i;
    }

    for(int i=2;i*i<lmt; i++){
        if(spf[i]==i){
            for(int j=i; j<lmt; j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
}

int main(){
    pre();
    int t; cin>>t;
    for(int i=1; i<=t; i++){
        int n; cin>>n;
        cout<<"Case "<<i<<":";
        while(n!=1){
            cout<<" "<<spf[n];
            while(spf[n/spf[n]]==spf[n]){
                n /= spf[n];
            }
            n /= spf[n];
        }
        cout<<"\n";
    }
}