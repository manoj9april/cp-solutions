#include<bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;
    int len = s.length();
    for(int i=0; i<len; i++){
        if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u') s[i]='1';
        else s[i]='0';
    }
    int ans=0,ln=0;
    for(int i=0; i<len; i++){
        if(s[i]=='1'){
            ln++;
            ans = max(ans,ln);
        }else ln=0;
    }

    cout<<ans<<"\n";
}