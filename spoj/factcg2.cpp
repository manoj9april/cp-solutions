#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt=1e7+3;

int spf[lmt];

void cal_spf(){

    for(int i=1; i<lmt; i++){
        spf[i]=i;
    }

    for(ll i=2; i*i<lmt; i++){
        if(spf[i]==i){
            for(ll j=i*i; j<lmt; j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}

int main(){
    cal_spf();
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    while(cin>>n){
        //string s="1x";
        cout<<'1';
        while(n!=1){
            //s = s+char(spf[n]+'0')+'x';
            cout<<" x "<<spf[n];
            n /= spf[n];
        }
        cout<<"\n";
    }
}