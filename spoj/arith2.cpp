#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll ans=0, ele;
        char ch='+';
        while(ch!='='){
            cin>>ele;
            if(ch=='+'){
                ans += ele;
            }else if(ch=='-'){
                ans -= ele;
            }else if(ch=='*'){
                ans *= ele;
            }else if(ch=='/'){
                ans /= ele;
            }
            cin>>ch;
        }

        cout<<ans<<endl;
    }
}