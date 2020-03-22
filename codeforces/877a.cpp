#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string t,tt,pat[5]={"Danil", "Olya", "Slava", "Ann", "Nikita"};
    cin>>t;
    int cnt=0;
    for(int k=0; k<5; k++){
        int n = pat[k].length();
        tt = pat[k]+'#'+t;
        int len = tt.length();
        int f[len];
        int j=0;
        f[0]=0;
        for(int i=1; i<len; i++){
            j = f[i-1];
            while(j>0 && tt[i]!=tt[j]) j = f[j-1];
            if(tt[i]==tt[j])j++;
            if(j==n)cnt++;
            f[i]=j;
        }
    }

    cout<<(cnt==1?"YES":"NO")<<"\n";
}