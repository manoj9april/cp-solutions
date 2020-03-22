#include<bits/stdc++.h>

using namespace std;

//class

int main(){
    int t; cin>>t; 
    while(t--){
        string s;
        int x,y;
        cin>>s>>x>>y;
        int acnt = 0,bcnt=0;
        int len = s.length();
        for(int i=0; i<len; i++){
            if(s[i]=='a') acnt++;
            if(s[i]=='b') bcnt++;
            
        }
        c=x; d=y;

        while(a || b){
            if((a>=b && c)||(a>0 && d==0))
        }
        /*
        string ss="";
        int mn=min(x,y);
        if(acnt>bcnt){
            while(acnt || bcnt){
                if(acnt>0)
                for(int i=1; i<=x && acnt>0; i++){
                    ss += 'a'; acnt--;
                }
                if(bcnt<=0) ss += '*';
                if(bcnt>0)
                for(int i=1; i<=y && bcnt>0; i++){
                    ss += 'b'; bcnt--;
                }
                if(acnt<=0) ss += '*';
            }
            int llen = ss.length();
            int j = ss.length()-1;
            while(ss[j]=='*'){
                ss[j]='5'; j--;
            }
            j=0;
            while(ss[j]!='5' && j<llen){
                cout<<ss[j]; j++;
            }
        }else{
            while(bcnt || acnt){
                if(bcnt>0)
                for(int i=1; i<=y && bcnt>0; i++){
                    ss += 'b'; bcnt--;
                }
                if(acnt<=0) ss += '*';
                if(acnt>0)
                for(int i=1; i<=x && acnt>0; i++){
                    ss += 'a'; acnt--;
                }
                if(bcnt<=0) ss += '*';
            }
            int llen = ss.length();
            int j = ss.length()-1;
            while(ss[j]=='*'){
                ss[j]='5'; j--;
            }
            j=0;
            while(ss[j]!='5' && j<llen){
                cout<<ss[j]; j++;
            }*/
        }
        cout<<"\n";
    }
    
}