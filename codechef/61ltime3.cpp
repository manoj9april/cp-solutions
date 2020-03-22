#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+8;
int ltt[4*lmt],rtt[4*lmt];
int mx[4*lmt];
int mn[4*lmt];
int lv[4*lmt];
int ans=0;

void tra(int i){
    if(ans==-1 || lv[i])return;
    int lt = ltt[i];
    int rt = rtt[i];
    tra(lt); tra(rt);
    if(mx[lt]<mn[rt]){ //lt rt
        mn[i]=mn[lt];
        mx[i]=mx[rt];
        return;
    }
    else if(mx[rt]<mn[lt]){ // rt lt
        ans++;
        //cout<<i<<"****\n";
        mn[i]=mn[rt];
        mx[i]=mx[lt];
        return;
    }
    ans=-1;
}

int main(){
    int t; cin>>t;
    lv[0]=1;
    while(t--){
        ans=0;
        int n; cin>>n;
        int l,r;
        for(int i=1; i<=n; i++){
            lv[i]=ltt[i]=rtt[i]=mx[i]=mn[i]=0;
            cin>>l>>r;
            if(l==-1){
                lv[i]=1;
                mx[i]=mn[i]=r;
            }else{
                ltt[i]=l;rtt[i]=r;
            }
        }

        tra(1);
        cout<<ans<<"\n";
    }
}