#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int a[m];
    memset(a,0,sizeof a);
    string s[n];

    for(int i=0; i<n; i++){
        cin>>s[i];
        for(int j=0; j<m; j++){
            if(s[i][j]=='1') a[j]++;
        }
    }
    bool ok=false;
    for(int i=0; i<n; i++){
        
        int cnt=0;
        for(int j=0; j<m; j++){
            if(s[i][j]=='1' && a[j]>1){
                cnt++;
            }else if(s[i][j]=='0')cnt++;
        }

        if(cnt==m){
            ok=true;
            break;
        }
    }

    cout<<(ok?"YES\n":"NO\n");

}