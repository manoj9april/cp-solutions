#include<bits/stdc++.h>

using namespace std;

string str[8]={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

int main(){
    string s;
    cin>>s;
    int n = s.length();

    bool v[26];
    for(int i=0; i<26; i++)v[i]=false;

    int num; char c;

    if(n){
        num = s[0]-'0';
        c = str[num-2][0];
        v[c-'a']=true;
    }

    for(int i=1; i<n; i++){
        num = s[0]-'0';
        c = str[num-2][0];
        v[c-'a']=true;

        int pre = s[i-1]-'0';pre--;
        if(s[i]=='7'||s[i]=='9'){
            num = s[0]-'0';
            c = str[num-2][pre%4];
            v[c-'a']=true;
        }else{
            num = s[0]-'0';
            c = str[num-2][pre%3];
            v[c-'a']=true;
        }
    }

    int cnt=0;
    for(int i=0; i<26; i++){
        if(v[i])cnt++;
    }
    cout<<cnt<<"\n";
}

