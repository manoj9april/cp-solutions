#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,m,x,k;
        cin>>n>>m>>x>>k;
        string str; cin>>str;
        int O=0,o=0,E=0,e=0;
        int len=str.length();
        for(int i=0; i<len; i++){
            if(str[i]=='O')O++;
            else E++;
        }
        o=O; e=E;
        //cout<<"\n"<<o<<n<<e<<"\n";
        for(int i=1; i<=m; i++){
            if(i%2==1){
                n -= min(o,x);
                o -= min(o,x);
            }else{
                n -= min(e,x);
                e -= min(e,x);
            }
        }
        //cout<<"\n"<<o<<n<<e<<"\n";
        cout<<(n<=0?"yes":"no")<<"\n";
    }
}