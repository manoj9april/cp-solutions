#include<bits/stdc++.h>

using namespace std;

//class

int main(){
    int t; cin>>t; 
    while(t--){
        int n;
        cin>>n;

        unsigned long long M = 4294967295;
        M = M - (n-2)*2;
        cout<<2<<" ";
        cout<<M<<" ";
        for(int i=0; i<n-2; i++){
            cout<<4<<" ";
        }
        cout<<"\n";
    }
    
}