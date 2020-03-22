#include<bits/stdc++.h>

using namespace std;

#define ll long long

#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)

int const lmt = 1e5+7;

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        if(n==1){
            cout<<-1<<"\n";
        }else{
            for(int i=0; i<n-1; i++) cout<<5;
            cout<<4<<"\n";
        }
    }
    
}