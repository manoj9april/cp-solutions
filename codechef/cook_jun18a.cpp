#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        long long a,b,n;
        cin>>a>>b>>n;
        int ans;
        if(n%2==0){
            if(abs(a)>abs(b))ans=1;
            else if(abs(a)<abs(b))ans =2;
            else ans=0;
        }else{
            if(a<0 && b<0){
                if(abs(a)>abs(b))ans=2;
                else if(abs(a)<abs(b))ans =1;
                else ans=0;
            }else if(a<0){
                ans=2;
            }else if(b<0){
                ans=1;
            }else{
                if(abs(a)>abs(b))ans=1;
                else if(abs(a)<abs(b))ans =2;
                else ans=0;
            }
        }

        cout<<ans<<"\n";
    }
}