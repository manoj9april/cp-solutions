#include<bits/stdc++.h>

using namespace std;

#define ll long long
int const lmt = 2e5+8;
bool check[lmt];

int main(){
    int n; cin>>n;

    memset(check, false, sizeof check);

    int c;
    for(int i=0; i<n; i++){
        cin>>c;
        if(c==0)continue;
        c += 1e5;
        check[c]=true;
    }

    int cnt=0;
    for(int i=0; i<lmt; i++){
        if(check[i])cnt++;
    }

    cout<<cnt<<"\n";
}