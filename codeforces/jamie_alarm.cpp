#include <bits/stdc++.h>

using namespace std;

int main(){
    int x;cin>>x;

    int a,b; cin>>a>>b;

    
    int ans=0;
    while(a/10!=7 && a%10!=7 && b/10!=7 && b%10!=7){
        b -= x;
        if(b<0){
            a--;
            b+=60;
        }
        if(a<0){
            a+=24;
        }
        ans++;
    }

    cout<<ans<<"\n";
}