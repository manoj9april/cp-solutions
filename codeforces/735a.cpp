#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n,j;
    cin>>n>>j;
    string s; cin>>s;
    int g,t;
    for(int i=0; i<n; i++){
        if(s[i]=='G')g=i;
        if(s[i]=='T')t=i;
    }
    if(t<g)j=-j;
    bool ok=false;
    for(int i=g; i<n && i>=0; i+=j){
        if(s[i]=='T'){
            ok=true;
            break;
        }else if(s[i]=='#')break;
    }
    cout<<(ok?"YES":"NO")<<"\n";
}

