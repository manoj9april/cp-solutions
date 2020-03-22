#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll n,m,a,b;
    cin>>n>>m>>a>>b;
    ll ex = n%m;
    cout<<min(ex*b,(m-ex)*a)<<"\n";
}