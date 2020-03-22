#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e5+6;

int ck[26];
int main(){
    int t; cin>>t;
    string s;
    while(t--){
        memset(ck,0,sizeof ck);
        cin>>s;
        int len = s.length();
        for(int i=0; i<len; i++){
            ck[s[i]-'a']++;
        }
        bool ok=true;
        for(int i=0; i<26; i++){
            if(ck[i]%2==1){
                ok=false;
                break;
            }
        }

        cout<<(ok?1:-1)<<"\n";
    }
}