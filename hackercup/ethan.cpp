#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    freopen("ethan.in","r",stdin);
    freopen("ethan.out","w",stdout);
    int t; cin>>t;
    string s;
    for(int tt=1; tt<=t; tt++){
        //
        cin>>s;
        int n = s.length();
        int f[n];
        f[0]=0;
        int j=0;
        for(int i=1; i<n; i++){
            j = f[i-1];
            while(j>0 && s[i]!=s[j]) j = f[j-1];

            if(s[i]==s[j])j++;
            f[i]=j;
        }
        bool one=false,zero=false;
        int k=0;
        if(!one && !zero){
            while(k<n && f[k]==0)k++;
        }
        if(k<n && f[k])one=true;
        if(one && !zero){
            while(k<n && f[k])k++;
        }
        if(k<n && f[k]==0)zero=true;
        //
        cout<<"Case #"<<tt<<": ";
        //
        if(one && zero){
            k=0;
            while(k<n && f[k]==0){cout<<s[k];k++;}
            cout<<s;
        }else{
            cout<<"Impossible";
        }
        //
        cout<<"\n";
    }
}
