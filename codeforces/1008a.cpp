#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string s; cin>>s;
    int n = s.length();
    bool ok=true;
    for(int i=0; i<n; i++){
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' &&s[i]!='u' && s[i]!='n'){
            if(i==n-1){
                ok = false; break;
            }else if(s[i+1]!='a' && s[i+1]!='e' && s[i+1]!='i' && s[i+1]!='o' &&s[i+1]!='u'){
                ok = false; break;
            }
        }
    }
    cout<<(ok?"YES":"NO")<<"\n";
}

