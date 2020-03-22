#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    int a;

    for(int i=0; i<n ;i++){
        cin>>a;
        cout<<(a%2==0?(a-1):a)<<" ";
    }
    cout<<"\n";
}

