#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    
    long long n;
    string s;
    while(t--){
        cin>>n;
        n++;
        s="";
        while(n!=1){
            if(n&1){
                s = '6'+s;
            }else{
                s = '5'+s;
            }
            n >>= 1;
        }
        cout<<s<<"\n";
    }
}