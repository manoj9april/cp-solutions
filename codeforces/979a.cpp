#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin>>n;
    if(n==0){
        cout<<0<<"\n";
        return 0;
    }
    
    n++;

    cout<<(n%2==0?n/2:n)<<"\n";
}