#include<bits/stdc++.h>

using namespace std;

#define ll long long



int main(){
    ll a,b;
    string s;
    cin>>a>>b>>s;

    int n = s.length();

    ll ans=1;
    for(int i=0; i<n; i++){
        if(s[i]=='1'){
            ans = (ans*a)%b;
        }
        a = (a*a)%b;
    }

    cout<<ans<<"\n";
}