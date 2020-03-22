#include<bits/stdc++.h>

using namespace std;
#define ll long long

vector<ll> v;
int main(){
    int t; cin>>t;
    while(t--){
        v.clear();
        int n; cin>>n;
        int arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                v.push_back(1LL*arr[i]+arr[j]);
            }
        }
        ll p;
        cin>>p;
        bool ok=false;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                if(binary_search(arr+j+1,arr+n,p-arr[i]-arr[j])){
                    ok=true;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<"\n";
    }    
}