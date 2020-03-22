#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll n,m,k;
    cin>>n>>m>>k;
    if(k<n){
        cout<<(k+1)<<" "<<(1)<<"\n";
    }else{
        k=k-n;
        ll st = k%(m-1);
        ll row = k/(m-1);
        if(row%2==0){
            // left to rt
            cout<<(n-row)<<" "<<(2+st)<<"\n";
        }else{
            //rt to lt
            cout<<(n-row)<<" "<<(m-st)<<"\n";
        }
    }
}