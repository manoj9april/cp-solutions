#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n;
    cin>>n;
    ll a,b,sa=0,sb=0;
    for(int i=0; i<n; i++){
        cin>>a;
        sa+=a;
    }
    for(int i=0; i<n; i++){
        cin>>b;
        sb+=b;
    }
    cout<<(sb<=sa?"YES":"NO")<<"\n";
}

