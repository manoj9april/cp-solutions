#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("evend.in","r",stdin);
    freopen("evend.out","w",stdout);
    int t;
    cin>>t;
    for(int tt=1; tt<=t; tt++){
        string s;
        cin>>s;

        int flag=0;
        long long n=0,small=0,big=0;
        int len = s.length();
        for(int i=0; i<len; i++){
            n = 10*n + (s[i]-'0');
            if(flag==0 && (s[i]-'0')%2==1){
                small = 10*small + (s[i]-'0')-1;
                if(s[i]=='9'){
                    big = 10*big + (s[i]-'0')+11;
                }else{
                    big = 10*big + (s[i]-'0')+1;
                }
                flag=1;
                continue;
            }
            if(flag==0){
                small = 10*small + (s[i]-'0');
                big = small;
            }else{
                small = 10*small + 8;
                big = 10*big;
            }
        }

        //cout<<min(big-n,n-small)<<"\n";
        //cout<<big<<" "<<small<<" "<<n<<"\n";
        cout<<"Case #"<<tt<<": "<<min(big-n,n-small)<<"\n";
    }
}