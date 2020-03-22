#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int len = s.length();
        long long c,h,e,f;
        c=h=e=f=0;
        for(int i=0; i<len; i++){
            if(s[i]=='c')c++;
            else if(s[i]=='h')h++;
            else if(s[i]=='e')e++;
            else if(s[i]=='f')f++;
        }
        long long ans = min(min(c,h),min(e,f));
        if(ans=0){
            cout<<"normal\n";
        }else{
            cout<<"lovely "<<ans<<"\n";
        }
    }
}