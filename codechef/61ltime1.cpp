#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+8;

int main(){
    int t; cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int cnt=0;
        while(l<=r && l%10){
            if(l%10==2 || l%10==3 || l%10==9)cnt++;
            l++;
        }
        while(l<=r && r%10){
            if(r%10==2 || r%10==3 || r%10==9)cnt++;
            r--;
        }
        if(l<r){
            cnt += ((r-l)/10)*3;
        }

        cout<<cnt<<"\n";
    }
}