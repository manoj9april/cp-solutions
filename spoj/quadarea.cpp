#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<<setprecision(2)<<fixed;
    int t; cin>>t;
    long double ans,a,b,c,d,s;
    while(t--){
        cin>>a>>b>>c>>d;

        s = (a+b+c+d)/2;
        ans = sqrt((s-d)*(s-a)*(s-b)*(s-c));

        cout<<ans<<"\n";
    }
}