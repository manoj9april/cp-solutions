#include<bits/stdc++.h>

using namespace std;

string solve(string s, int k){
    if(k==1){
        return s;
    }
    int ne=0;

    for(int i=0; i<k; i++){
        ne += (s[i]-'0');
    }
    string str= to_string(ne);

    return solve(str,str.length());
}

int main(){
    int k;
    string s;
    cin>>s>>k;

    int len = s.length();
    s = solve(s,len);

    s = to_string((s[0]-'0')*k);
    len = s.length();
    
    cout<<solve(s,len)<<"\n";
}