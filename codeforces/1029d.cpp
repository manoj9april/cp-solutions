#include<bits/stdc++.h>
#include<string>
using namespace std;
#define ll long long

int const lmt = 2e5+3;
map<int, map<int, int> > mp;  // digit , mod ==> fre
ll n,k,x,y;
ll a[lmt],dg[lmt];
ll powtn[11];

void pre(){
    powtn[0]=1;
    for(int i=1; i<=10; i++){
        powtn[i] = (powtn[i-1]*10)%k;
    }
}

int main(){
    cin>>n>>k;
    pre();
    for(int i=0; i<n; i++){
        cin>>a[i];
        dg[i] = (to_string(a[i])).length();
        mp[dg[i]][a[i]%k]++;
    }

    ll cnt=0;
    for(int i=0; i<n; i++){
        for(int d=1; d<=10; d++){
            x = (a[i]*powtn[d])%k;
            y = (k-x)%k;
            if(mp[d].find(y) != mp[d].end())
                cnt += mp[d][y];
        }
        x = (a[i]*powtn[dg[i]])%k;
        x = (x+a[i]%k)%k;
        if(x==0)cnt--;
    }
    cout<<cnt<<"\n";
}

