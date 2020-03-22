#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    ll rtn = sqrt(n);
    for(int i=n-rtn+1; i>-rtn; i-=rtn){
        for(int j=0; j<rtn; j++){
            if(i+j>0)cout<<(i+j)<<" ";
        }
    }
    cout<<"\n";
}

// 3 4 1 2 7 8 5 6