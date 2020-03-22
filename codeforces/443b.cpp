#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 2e6+3;
bool ck[lmt];

string s;
int main(){
    ll k,n;
    cin>>s>>k;
    for(int i=0; i<k; i++) s+='.';
    n = s.length();
    ll gl=0;
    for(ll i=n/2; i>=1; i--){
        memset(ck,false, sizeof ck);
        for(int j=0; j+i<n; j++ ){
            if( (s[j]==s[j+i]) || (s[j+i]=='.') ){ ck[j]=true;}
        }
        ll ans=0,l=0;
        bool ok=false;
        for(int j=0; j<n; j++){
            //if(i==3)cout<<ck[j]<<" ";
            if(ck[j]){
                l++;
                ans = max(ans,l);
                if(ans>=i){ ok=true; break;}
            }
            else{
                l=0;
            }
        }
        if(ok){
            gl = i;break;
        }
    }
    cout<<(2*gl)<<"\n";
}

