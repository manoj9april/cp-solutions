#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

ll zero[12],one[12];
ll val[12];
int main(){
    int n,m,q;
    cin>>n>>m>>q;
    string s;
    for(int i=0; i<n; i++) cin>>val[i];
    for(int j=0; j<m; j++){
        cin>>s;
        for(int i=0; i<n; i++){
            if(s[i]=='1')one[i]++;
            else zero[i]++;
        }
    }
    ll ans,k;
    while(q--){
        cin>>s>>k;
        ans=0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') ans += zero[i]*val[i];
            else ans += one[i]*val[i];
        }
        cout<<ans<<"\n";
    }
}

