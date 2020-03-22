#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int b=0,a=0,ans=0;
    for(int i=0; i<n; i++){
        if(s[i]=='a'){
            a=1;
            while(i+1<n && s[i+1]==s[i]){a++; i++;}
            ans = max(ans,a+b);
        }else{
            b=a+1;
            while(i+1<n && s[i+1]==s[i]){b++; i++;}
            ans = max(ans,b);
        }
    }
    cout<<ans<<"\n";
}