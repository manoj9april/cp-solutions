#include<bits/stdc++.h>

using namespace std;
#define ll long long

#define rep(idx, from, to, inc) for (int idx=from ; i<=to ; idx+=inc)
#define loop(i,n) rep(i,0,n-1,1)

int const MAXA = 1.5e7+7;
int const MAXN = 3e5+7;

int a[MAXN];
vector<bool> used(MAXA,false);
int occ[MAXA+1];

int main(){
    ios::sync_with_stdio(0);
    int n; cin>>n;
    int g=0;
    loop(i,n){
        cin>>a[i];
        g = __gcd(g,a[i]);
    }
    int mx=0;
    loop(i,n){
        a[i] /= g;
        occ[a[i]]++;
        mx = max(mx,a[i]);
    }

    ll ans=0,cnt;
    for(int i=2; i<min(mx+1,MAXA); i++){
        if(!used[i]){
            cnt=0;
            for(int j=i; j<min(mx+1,MAXA); j+=i){
                used[j]=true;
                cnt += occ[j];
            }
            ans = max(ans,cnt);
        }
    }

    if(ans==0){
        cout<<-1<<"\n";
    }else{
        ans = n-ans;
        cout<<ans<<"\n";
    }
}