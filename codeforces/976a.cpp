#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;
    string s;
    cin>>s;
    if(n==1){
        cout<<s<<'\n';
        return 0;
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i]=='0') cnt++;
    }
    cout<<'1';

    for(int i=0; i<cnt; i++){
        cout<<'0';
    }
    cout<<"\n";
}