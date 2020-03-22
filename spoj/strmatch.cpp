#include<bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m,cnt;
    cin>>n>>m;
    string text,pat,s;
 
    cin>>text;
    while(m--){
        cnt=0;
        cin>>pat;
        int pl = pat.length();
        if(pat.length()>n){
            cout<<"0\n";
            continue;
        }
        
        s = pat + '#' + text;

        int f[s.length()];
        int len=s.length(); 
        f[0]=0;
        int j;
        for(int i=1; i<len; i++){
            j = f[i-1];

            while(j>0 && s[j]!=s[i]){
                j = f[j-1];
            }

            if(s[i]==s[j]) j++;

            f[i]=j;
            if(j==pl) cnt++;
        }

        cout<<cnt<<"\n";
    }

}