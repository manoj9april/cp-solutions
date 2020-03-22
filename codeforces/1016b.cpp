#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+4;
ll pre[lmt];

int main(){
    int n,m,q; cin>>m>>n>>q;
    string s,t;
    cin>>s>>t;
    string tt = t+'#'+s;
    int len = tt.length();
    int f[len];
    int j=0;
    f[0]=0;
    //cout<<tt<<"\n";
    for(int i=1; i<len; i++){
        j = f[i-1];
        while(j>0 && tt[i]!=tt[j])j=f[j-1];
        if(tt[i]==tt[j])j++;
        f[i]=j;
        //cout<<j<<" ";
        if(j==n){pre[i+1-(n+1)]=1;}// cout<<"hi\n";}
    }
    for(int i=1; i<=m; i++){
        //cout<<pre[i]<<" ";
        pre[i] += pre[i-1];
        
    }
    
    int l,r;
    while(q--){
        cin>>l>>r;
        if(r-l+1<n)cout<<"0\n";
        else cout<<max(1ll*0,pre[r]-pre[l+n-2])<<"\n";
    }

}

