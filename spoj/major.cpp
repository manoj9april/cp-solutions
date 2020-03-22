#include<bits/stdc++.h>

using namespace std;

int cnt[1000008];

int main(){
    int t,n,ele,idx,mx; cin>>t;
    while(t--){
        mx=0;
        memset(cnt,0,sizeof cnt);
        cin>>n;
        for(int i=0; i<n; i++){
            cin>>ele;
            cnt[ele+1000]++;
            if(cnt[ele+1000]>mx){
                mx = cnt[ele+1000];
                idx = ele;
            }
        }
        if(n==0){
            cout<<"NO\n";
        }else if(n==1){
            cout<<"YES "<<ele<<endl;
        }else{
            if(mx>n/2){
                cout<<"YES "<<idx<<endl;
            }else{
                cout<<"NO\n";
            }
        }
    }
}