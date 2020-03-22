#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll n; cin>>n;
    int cnt=0;
    while(n!=1){
        cnt++;
        //if(n%2)cnt++;
        n = (n+1)/2;
    }
    cout<<(cnt)<<"\n";
}

