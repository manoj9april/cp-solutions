#include<bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    string s;
    cin>>s;
    while(s[0]!=0 && s[1]!=0 && s[3]!=0){
        n = stoll(s);
        cout<<n<<"\n";
        cin>>s;
    }
}