#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 1001;
ll cnt[32];
ll ct[32];
void cop(){
    for(ll i=0; i<32; i++){
        ct[i]=cnt[i];
        //cout<<cnt[i]<<" ";
    }
}

ll solve(ll b, ll g){
    ll j=0;
    if(b==-1) return -1;
    if(ct[b]>=g){
        ct[b]-=g;
        return g;
    }
    else if(ct[b]){
        j=ct[b];
        g -= ct[b]; ct[b]=0;

    }
    ll ans = solve(b-1,g<<1);
    if(ans==-1)return -1;
    return j + ans;
}

int main(){
    ll n,q,a; cin>>n>>q;
    for(ll i=0;i<n; i++){
        cin>>a;
        cnt[(ll)log2(a)]++;
    }
    //cop();
    ll b=1;
    ll ans;
    while(q--){
        cop();
        ans=0;
        cin>>a;
        b=0;
        ll pre=0;
        while(a){
            if(a&1){
                pre = solve(b,1);
                if(pre==-1)break;
                ans+=pre;
            }
            b++;
            a >>= 1;
        }

        cout<<(pre==-1?pre:ans)<<"\n";
    }
}