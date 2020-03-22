#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    bool same=true;
    for(int i=1; i<n; i++){
        if(s[i]!=s[0]){
            same=false; break;
        }
    }
    if(same){
        for(int i=1; i<k; i++){
            s+=s[0];
        }
        cout<<s<<"\n";
        return 0;
    }
    
    int f[n]; f[0]=0;
    int j=0;
    for(int i=1; i<n; i++){
        while(j>0 && s[j]!=s[i])j=f[j-1];
        if(s[i]==s[j])j++;
        f[i]=j;
    }

    string st = s.substr(f[n-1]);
    //cout<<st<<"\n";
    for(int i=1; i<k; i++){
        s += st;
    }
    cout<<s<<"\n";
}


