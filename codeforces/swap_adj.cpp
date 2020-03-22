#include<bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n; cin>>n;

    int a[n+1],pre[n+1];
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    string s; cin>>s;
    int len = s.length();
    pre[0]=pre[1]=0;
    for(int i=0; i<len; i++){
        pre[i+2] = pre[i+1] + (s[i]-'0');
    }
    //for(int i=1; i<=n; i++) cout<<pre[i]<<" ";
    //cout<<"\n";
    bool ok =true;
    for(int i=2; i<=n; i++){
        if(a[i]<a[i-1]){
            if(pre[i]-pre[a[i]]!=i-a[i]){
                ok=false;
                break;
            }
            a[i]=a[i-1];
        }
    }
    cout<<(ok?"YES":"NO")<<"\n";
}