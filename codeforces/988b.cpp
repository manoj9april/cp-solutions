#include<bits/stdc++.h>

using namespace std;

string str[100];

bool comp(string f, string s){
    return f.length()<=s.length();
}

int main(){
    int n; cin>>n;
    bool ok=true;
    for(int i=0; i<n; i++){
        cin>>str[i];
    }
    sort(str,str+n,comp);

    
    for(int i=1; i<n; i++){
        if(str[i].find(str[i-1])== string::npos){
            ok=false;
            break;
        }
    }

    if(ok){
        cout<<"YES\n";
        for(int i=0; i<n; i++){
            cout<<str[i]<<"\n";
        }
    }else{
        cout<<"NO\n";
    }
}