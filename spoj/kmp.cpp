#include<bits/stdc++.h>

using namespace std;

int main(){
    
    string p,t,str;
    
    cin>>p>>t;
    int m=p.length();
    str = p+'#'+t;
    
    int cnt=0;
    int len = str.length();
    int f[len];
    f[0]=0;
    for(int i=1; i<len; i++){
        int j=f[i-1];
        
        while(j>0 && str[i]!=str[j]){
            j = f[j-1];
        }
        
        if(str[i]==str[j])++j;
        
        f[i]=j;
        if(j==m) cnt++;
    }
    
    cout<<cnt<<"\n";
}