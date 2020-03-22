#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    freopen("inter.in","r",stdin);
    freopen("inter.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        int n,a; cin>>n;
        for(int i=0; i<=n; i++)cin>>a;
        //
        cout<<"Case #"<<tt<<": ";
        //
        if(n%2==0){
            cout<<"0";
        }else{
            cout<<"1\n0.0";
        }
        //
        cout<<"\n";
    }
}
