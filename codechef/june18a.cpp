oo#include<bits/stdc++.h>

using namespace std;

int main(){
    cout<<fixed;
    int t; cin>>t;
    while(t--){
        long double n,a,b,f=0,s=0,c;
        cin>>n>>a>>b;
        
        for(int i=0; i<n; i++){
            cin>>c;
            if(c==a)f+=1;
            if(c==b)s+=1;
        }

        long double ans = f/n;
        ans *= s/n;
        cout<<(ans)<<"\n";
    }
}