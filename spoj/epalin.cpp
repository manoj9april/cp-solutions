#include<bits/stdc++.h>

using namespace std;



int main(){
    string s,rev;
    while(cin>>rev){
        s = rev;
        reverse(rev.begin(), rev.end());
        if(s==rev){
            cout<<s<<"\n";
            continue;
        }
        int len = s.length();
        int fr[len];
        fr[0]=0;

        int j;
        for(int i=1; i<len; i++){
            j = fr[i-1];

            while(j>0 && rev[i]!=rev[j]){
                j = fr[j-1];
            }

            if(rev[i]==rev[j])  j++;

            fr[i]=j;
        }

        for(j=len-1; j>=0; j--){
            if(fr[j]==j) break;
        }
        cout<<s;
        for(j=j+1; j<len; j++){
            cout<<rev[j];
        }
        cout<<endl;
    }
}