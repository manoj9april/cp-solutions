#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int ck[101];
int main(){
    int n;
    cin>>n;
    int a;
    int ans=0;
    for(int i=0; i<n; i++){
        cin>>a;
        ck[a]++;
        ans = max(ans,ck[a]);
    }
    cout<<ans<<"\n";
}