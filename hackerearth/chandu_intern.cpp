#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e7+3;

int spf[lmt];

void pre(){
    for(int i=1; i<lmt; i++) spf[i]=i;

    for(ll i=2; i<lmt; i++){
        if(spf[i]==i){
            for(ll j=2*i; j<lmt; j+=i){
                spf[j]=i;
            }
        }
    }
}

int main(){
    pre();
    int t; cin>>t;
    while(t--){
        ios_base::sync_with_stdio(0);
        cin.tie(0); cout.tie(0);
        
        int n;
        cin>>n;
        
        if(spf[n]==n){
            cout<<"NO\n";
            continue;
        }
        int cnt=0;
        while(n!=1){
            n /= spf[n];
            cnt++;
            if(cnt>1) break;
        }

        cout<<(cnt>1?"YES":"NO")<<"\n";
    }
}