#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
map<int,int> my;

int main(){
    string s; cin>>s;
    int n = s.length();
    my[0]=1;
    ll sum=0,cnt=0;
    for(int i=0; i<n; i++){
        sum += (s[i]-'0');
        if(my[sum%3] || s[i]=='0'){
            sum=0;
            cnt++;
            my.clear();
            my[0]=1;
        }else{
            my[sum%3]++;
        }
    }
    cout<<cnt<<"\n";
}

