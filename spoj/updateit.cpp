#include<bits/stdc++.h>

using namespace std;

int main(){
    std::ios::sync_with_stdio(false);
    
    int t; cin>>t;
    while(t--){
        int n,u;
        cin>>n>>u;
        int a[n+1];

        memset(a, 0, sizeof a);

        int l,r,val;
        while(u--){
            cin>>l>>r>>val;
            a[l] += val;
            a[r+1] -=val;
        }
        int temp=0;
        for(int i=0; i<n; i++){
            temp = a[i] = temp + a[i];
        }

        int q; cin>>q;
        int idx;
        while(q--){
            cin>>idx;
            cout<<a[idx]<<endl;
        }

    }
}