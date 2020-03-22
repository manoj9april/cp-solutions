#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    ll a,b,c;
    cin>>a>>b>>c;
    ll ans,an =0;
    int s = min(a,min(b,c));
    for(int i=0; i<=min(s,2); i++){
        ans = i;
        ans += ((a-i)/3 + (b-i)/3 +(c-i)/3);
        an = max(an,ans);
    }

    cout<<an<<"\n";
}