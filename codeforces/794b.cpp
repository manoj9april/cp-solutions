#include<bits/stdc++.h>

using namespace std;

int main(){
    long double n,h;
    cin>>n>>h;
    cout<<fixed<<setprecision(12);
    for(int i=1; i<n; i++){
        cout<<(sqrt(i/n)*h)<<" ";
    }
    cout<<"\n";
}