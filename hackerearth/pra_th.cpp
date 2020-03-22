#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define in first
#define out second

int const lmt = 1e5+6;

int t1[lmt];
pair<int,int> t[lmt];
int pre[lmt];
int main(){
    int tt; cin>>tt;
    while(tt--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>t[i].in>>t[i].out;
            t1[i]=t[i].in;
        }

        sort(t1,t1+n);
        sort(t,t+n);
        int idx,ans=0;
        for(int i=0; i<n; i++){
            pre[i]=0;
            idx = lower_bound(t1,t1+n,t[i].out)-(t1);
            pre[i]++;pre[idx]--;
        }
        ans = pre[0];
        for(int i=1; i<n; i++){
            pre[i]+=pre[i-1];
            ans = max(pre[i],ans);
        }

        cout<<ans<<"\n";
    }    
}