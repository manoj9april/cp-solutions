#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll g,x,y;

void euclid(ll a,ll b){
    if(b==0){
        g=a;
        x=1;
        y=0;
    }else{
        euclid(b, a%b);

        ll temp = x;
        x=y;
        y = temp - (a/b)*y;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        ll a,b,d;
        cin>>a>>b>>d;
        euclid(a,b);

        if(d%g!=0){
            cout<<0<<"\n";
            continue;
        }

        euclid(a/g,b/g);
        cout<<y<<"jdkj\n";
        ll y1 = ((d%a)* (y%a)) %a;
        if((d-b*y1)%a!=0){
            cout<<0<<"\n";
            continue;
        }

        cout<<((d/b - y)/a)<<endl;
    }
}