#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,x;
    cin>>n>>x;
    x = 240-x;
    int ans = -1+sqrt(1.0+(double)(8*x/5));
    ans /=2;
    cout<<(ans>n?n:ans)<<endl;
}