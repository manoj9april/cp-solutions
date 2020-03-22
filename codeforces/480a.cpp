#include<bits/stdc++.h>

using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();

    int o=0,k=0;
    for(int i=0; i<n; i++){
        if(s[i]=='o') o++;
        else k++;
    }
    if(k==0||o==0){
        cout<<"YES\n";
        return 0;
    }
    cout<<(k%o==0?"YES":"NO");
    cout<<"\n";
    return 0;
}