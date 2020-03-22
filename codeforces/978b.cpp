#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int n,ans=0; cin>>n;
    string s; cin>>s;
    for(int i=0; i<n; i++){
        if(s[i]=='x'){
            int cnt=1;
            while(i+1<n && s[i+1]==s[i]){cnt++;i++;}
            if(cnt>=3)ans += (cnt-2);
        }
    }

    cout<<ans<<"\n";
}