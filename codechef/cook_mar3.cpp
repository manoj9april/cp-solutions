#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int const MOD = 1e9 +7;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        ll n,q,k;
        cin>>n>>q>>k;

        ll a[n+1];
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        bool nosol =false;
        char ty;
        int l,r;
        int query[n+1];
        memset(query, -1, sizeof query);
        ll extra=0;
        while(q--){
            cin>>ty>>l>>r;
            if(nosol) continue;
            if(ty=='D'){
                if(a[l]==-1){
                    a[l]=k;
                    query[l]=k-(r-l);
                }
                if(a[l]<=r-l){nosol =true; continue;}
                for(int i=l+1; i<=r; i++){
                    if(a[i]==-1){
                        a[i]=a[i-1]-1;
                    }else{
                        if(a[i]==a[i-1]-1) continue;
                        else{ nosol = true; break;}
                    }
                }
            }else{
                if(a[l]==-1){
                    a[l]=1;
                    query[l]=k-(r-l);
                }
                if(k-a[l]<r-l) {nosol =true; continue;}
                for(int i=l+1; i<=r; i++){
                    if(a[i]==-1){
                        a[i]=a[i-1]+1;
                    }else{
                        if(a[i]==a[i-1]+1) continue;
                        else{ nosol = true; break;}
                    }
                }
            }
        }
        if(nosol){
            cout<<"0\n";
            continue;
        }
        ll cnt=1;
        for(int i=1; i<=n; i++){
            if(query[i]==-1){
                if(a[i]==-1){
                    cnt = (cnt*k)%MOD;
                }
            }else{
                cnt = (cnt*query[i])%MOD;
            }
        }
        cout<<cnt<<"\n";
    }
}