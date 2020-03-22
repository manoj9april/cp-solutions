#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    string s;
    while(true){
        cin>>n>>s;
        if(n==-1)break;
        int len = s.length();

        if(n<len){
            cout<<"0\n";
            continue;
        }
        int f[len];
        f[0]=0;
        int j;
        for(int i=1; i<len; i++){
            j = f[i-1];

            while(j>0 && s[j]!=s[i]){
                j=f[j-1];
            }

            if(s[j]==s[i]) j++;

            f[i]=j;
        }

        int rem = len-f[len-1];
        int ans = (n-len)/rem;
        cout<<ans+1<<endl;
    }
}