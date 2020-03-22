#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        double l,d,t; cin>>l>>d>>t;
        double w = asin(d/l);
        double ans = l*sin(w*t);
        cout<<ans<<"\n";
    }
}