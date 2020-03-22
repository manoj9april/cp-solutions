#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll n; 
bool check(ll k){
    ll f=0,s=0;
    ll t=n;
    while(t){
        if(t>=k)
        {
            f +=k;
            t -= k;
        }else{
            f+=t;
            t=0;
        }
        s += (t/10);
        t  = t-t/10;
    }
    return f>=s;
}
int main(){
    cin>>n;
    ll lo=1,hi=n,mid;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        if(check(mid)) hi=mid-1;
        else lo = mid+1;
    }

    cout<<lo<<"\n";
}