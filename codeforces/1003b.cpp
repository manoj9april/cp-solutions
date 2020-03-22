#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int a[2],x;
    cin>>a[0]>>a[1]>>x;

    int f = (x%2==1);

    string s="";x++;
    for(int i=0; i<x-2; i++){
        a[f]--;
        s += (char)('0'+f);
        f = 1-f;
    }
    while(a[1]){
        s += '1';
        a[1]--;
    }
    while(a[0]){
        s+='0';
        a[0]--;
    }
    cout<<s<<"\n";
}