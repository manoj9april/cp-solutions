#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string a="",b="",ans;
        int f=0,s=0;
        if(n==0){
            cout<<"Draw\n"; continue;
        }else{
            cin>>a;
        }
        string ele;
        for(int i=1; i<=n; i++){
            cin>>ele;
            if(a==ele)f++;
            else{
                b=ele; s++;
            }
        }
        if(f>s)cout<<a;
        else if(s>f)cout<<b;
        else cout<<"Draw";

        cout<<endl;
    }
}
