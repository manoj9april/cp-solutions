#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string s; cin>>s;
    int n = s.length();
    int r,b,y,g;
    int cnt[4]={0};
    for(int i=0; i<n; i++){
        if(s[i]=='R'){
            r=i%4;
        }else if(s[i]=='B'){
            b=i%4;
        }else if(s[i]=='Y'){
            y=i%4;
        }else if(s[i]=='G'){
            g=i%4;
        }else{
            cnt[i%4]++;
        }
    }
    cout<<cnt[r]<<" "<<cnt[b]<<" "<<cnt[y]<<" "<<cnt[g]<<"\n";
}

