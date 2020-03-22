#include<bits/stdc++.h>

using namespace std;
int gcd(int a,int b){
    if(b==0) return a;
    return gcd(b,a%b);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a,b;
        cin>>a;
        if(n==1){
            cout<<"NO\n";
            continue;
        }
        for(int i=1; i<n; i++){
            cin>>b;
            a = gcd(a,b);
        }

        cout<<(a==1?"YES":"NO")<<"\n";
    }
}


