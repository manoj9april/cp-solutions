#include<iostream>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a,ans;
        cin>>ans;

        for(int i=0; i<n-1; i++){
            cin>>a;
            ans = gcd(ans,a);
        }

        cout<<(ans==1?0:-1)<<"\n";
    }
}