#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

set<ll> a,b;
unordered_map<int,int> occ;
int arr[lmt];
int main(){
    int t; cin>>t;
    ll n,z1,z2;
    while(t--){
        cin>>n>>z1>>z2;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        b.insert(0);
        occ[0]++;
        bool found=false;
        int ans=0;
        while(a.size() || b.size()){
            for(auto it: b){
                for(int i=0; i<n; i++){
                    if(it+arr[i]==z1 || it+arr[i]==z2 ){
                        ans=1; found =true;break;
                    }else{
                        if(occ[it+arr[i]]) continue;
                        a.insert(it+arr[i]);
                        occ[it+arr[i]]++;
                    }
                    if(it-arr[i]==z1 || it-arr[i]==z2 ){
                        ans=1; found =true;break;
                    }else{
                        if(occ[it-arr[i]]) continue;
                        a.insert(it-arr[i]);
                        occ[it-arr[i]]++;
                    }
                }
            } b.erase(b.begin(),b.end());
            if(found)break;
            for(auto it: a){
                for(int i=0; i<n; i++){
                    if(it+arr[i]==z1 || it+arr[i]==z2 ){
                        ans=2; found =true;break;
                    }else{
                        if(occ[it+arr[i]]) continue;
                        b.insert(it+arr[i]);
                        occ[it+arr[i]]++;
                    }
                    if(it-arr[i]==z1 || it-arr[i]==z2 ){
                        ans=2; found =true;break;
                    }else{
                        if(occ[it-arr[i]]) continue;
                        b.insert(it-arr[i]);
                        occ[it-arr[i]]++;
                    }
                }
            }  a.erase(a.begin(),a.end());
            if(found)break;
        }
        if(found){
            cout<<ans<<"\n";
        }else{
            cout<<"0\n";
        }
    }
}

