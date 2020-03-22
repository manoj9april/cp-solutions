#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int lmt=1e6;

int a[lmt];
ll cnt,n,y;

void fun(ll x, int idx, ll sum){
    if(x<=0) return;
    while(x%2==0){
        x /= 2; idx++;
    }
    ll k = sum + pow(2,idx);

    if(k<n){
        if(a[k]>0){
            a[k] -= y;
            if(a[k]<=0) cnt--; 
        }
        
        fun(x/2, idx+1, k);
    }
    fun(x/2, idx+1, sum);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin>>n;
    cnt=n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    ll q;
    cin>>q;
    while(q--){
        ll x;
        cin>>x>>y;
        int idx=0;
        ll sum=0;
        if(a[0]>0){
            a[0] -= y;
            if(a[0]<=0) cnt--;
        }
        fun(x, idx, sum);
        cout<<cnt<<"\n";
    }
}