#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        
        int a[n],arr[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            arr[i]=i+1;
        }
        if(n==1){
            cout<<1<<"\n";
            continue;
        }
        int ans=0;
        do{
            bool ok=true;
            int cnt=0;
            for(int i=0; i<n; i++){
                if(a[i]==0 || a[i]==arr[i])continue;
                ok=false;
                break;
            }
            if(ok){
                for(int i=1; i<n; i++){
                    if(arr[i]>arr[i-1])cnt++;
                }
                if(cnt==k)ans++;
            }
        }while(next_permutation(arr,arr+n));

        cout<<ans<<"\n";
    }
}