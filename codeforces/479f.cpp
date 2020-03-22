#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    map<int,int> mp;
    int a[n];
    int ans =0;
    int idx=n-1;
    for(int i=0; i<n; i++){
        cin>>a[i];
        mp[a[i]] = mp[a[i]-1]+1;
        if(ans<mp[a[i]]){
            ans=mp[a[i]];
            idx = i;
        }
    }
    cout<<ans<<"\n";

    vector<int> v;
    while(ans--){
        v.push_back(idx);
        int j=idx;
        while(j>=0){
            if(a[j]==a[idx]-1){
                idx=j;
                break;
            }
            j--;
        }
    }

    for(int i=v.size()-1; i>=0; i--){
        cout<<v[i]+1<<" ";
    }cout<<"\n";
}