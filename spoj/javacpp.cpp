#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    while(cin>>s){
        string ans="";
        bool cpp,java;cpp=java=false;
        int len =s.length();
        if(s[0]=='_' || (s[0]>='A' && s[0]<='Z')){
            cout<<"Error!\n";
            continue;
        }
        for(int i=1; i<len; i++){
            if(s[i]=='_'){
                i++;cpp=true;
                if(s[i]>='A' && s[i]<='Z'){
                    ans="Error!";
                    break;
                }
                ans +=(char)('A'+s[i]-'a');
            }else if(s[i]>='A' && s[i]<='Z'){
                java=true;
                ans +=(char)('a'+s[i]-'A');
            }else if(cpp && java){
                ans="Error!";
                break;
            }else{
                ans += s[i];
            }
        }
        cout<<ans<<endl;
    }
}