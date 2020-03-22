#include<bits/stdc++.h>

using namespace std;


int main(){
    int n; cin>>n;

    string s;
    cin>>s;

    int f[n];
    f[0]=0;

    int j;
    for(int i=1; i<n; i++){
        j=f[i-1];

        while(j>0 && s[i]!=s[j]){
            j = f[j-1];
        }

        if(s[i]==s[j]) j++;

        f[i]=j;
    }

    int cnt=0;
    for(int i=n-1; i>=0;){
        //cout<<i<<" ";
        if(i%2==1 && f[i]>=(i+1)/2){
            //cnt -= (i+1)/2;
            i = i/2;
        }else i--;
        
        cnt++;
    }

    cout<<cnt<<"\n";
}