#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 4e3+5;
ll d[2][lmt];
int main(){
    ll n; cin>>n;
    ll x,y;
    while(n--){
        cin>>x>>y; x--; y--;
        d[0][x+y]++;
        d[1][999+x-y]++;
    }
    ll ans=0,o,e;
    for(int i=0; i<1000; i++){
        for(int j=0; j<2; j++){
            e = d[j][i];
            o = e-1;
            if(o%2==0)o=o/2;
            else if(e%2==0)e=e/2;
            ans += (o*e);
        }
    }
    cout<<ans<<"\n";
}

