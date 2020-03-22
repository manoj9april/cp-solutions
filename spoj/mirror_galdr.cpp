#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int len = s.length();
        bool palin=true;
        for(int i=0,j=len-1; i<j; i++,j--){
            if(s[i]!=s[j]){
                palin=false;
                break;
            }
        }
        cout<<(palin?"YES":"NO")<<endl;
    }
}