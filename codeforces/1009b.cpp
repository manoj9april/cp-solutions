#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int i=0,j=0,two,zero;
    int cnt[3];
    while(i<n){
        cnt[0]=cnt[1]=cnt[2]=0;
        while(j<n && s[j]!='2'){
            cnt[s[j]-'0']++;
            j++;
        }
        two=j;
        while(j<n && s[j]!='0'){
            cnt[s[j]-'0']++;
            j++;
        }
        zero=j;
        while(i<zero){
            if(cnt[0]){s[i]='0';cnt[0]--;}
            else if(cnt[1]){s[i]='1';cnt[1]--;}
            else if(cnt[2]){s[i]='2';cnt[2]--;}
            else break;
            i++;
        }
    }
    //cout<<s<<"\n";
    int one=0;
    for(i=0; i<n; i++){
        if(s[i]=='1'){
            one++;s[i]='*';
        }
    }
    i=0;
    string ans="";
    while(i<n && s[i]=='0'){
        i++;
        ans=ans+'0';
    }
    j=i;
    //cout<<ans<<"\n";
    while(one){
        ans=ans+'1';
        one--;
    }
    for(j=i; j<n; j++){
        if(s[j]!='*')ans=ans+s[j];
    }
    cout<<ans<<"\n";
}

