#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    string s;
    for(int i=0; i<=n; i++) cin>>s;

    cout<<(n%2==0 ? "home":"contest")<<"\n";
}