#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+3;
int a[lmt];
vector<bool> ck;
int main(){
    int n;
    cin>>n;
    ck.resize(n,false);
    for(int i=0; i<n; i++)cin>>a[i];
    sort(a,a+n);
    int up=1,cnt=0;
    for(int i=0; up<n && i<n; i++){
        while(up<n && (a[up]==a[i] || ck[up])){up++;
        }
        if(up<n){
            cnt++;
            ck[up]=true;
        }
    }
    cout<<cnt<<"\n";
}

