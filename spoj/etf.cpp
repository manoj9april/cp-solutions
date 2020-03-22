#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+1;

int spf[lmt];
bool prime[lmt];
void seive(){
    for(int i=1; i<lmt; i++){
        spf[i]=i;
        prime[i]=true;
    }

    for(int i=2; i*i<lmt; i++){
        if(prime[i]){
            for(int j=i*i; j<lmt; j+=i){
                if(spf[j]==j) spf[j]=i;

                prime[j]=false;
            }
        }
    }
}

int main(){
    seive();
    
    int t; cin>>t;
    while(t--){
        
        int n; cin>>n;

        int ans=n;
        while(n!=1){
            //cout<<"hbhjh\n";
            while(spf[n]==spf[n/spf[n]]) n /= spf[n];
            ans -= ans/spf[n];
            n /= spf[n];
        }

        cout<<ans<<endl;
    }
}