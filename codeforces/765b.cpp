#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    bool ck[27];
    memset(ck,false,sizeof ck);
    bool ok=true;
    ck[0]=true;
    string s; cin>>s;
    int len = s.length();
    for(int i=0; i<len; i++){
        if(!ck[s[i]-'a']){
            ok=false;
            break;
        }
        ck[s[i]-'a'+1]=true;
    }

    cout<<(ok?"YES":"NO")<<"\n";
}