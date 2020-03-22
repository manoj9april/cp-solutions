#include<bits/stdc++.h>

using namespace std;

string s;
int n;
vector<char> v;
bool chosen[100];

void call(int noc){
    if(noc==n){
        for(int i=0; i<n; i++){
            cout<<v[i];
        }cout<<'\n';
        return;
    }

    for(int i=0; i<n; i++){
        if(chosen[i]) continue;
        chosen[i]=true;
        v.push_back(s[i]);
        call(noc+1);
        chosen[i]=false;
        v.pop_back();
    }
}

int main(){
    memset(chosen,false,sizeof chosen);
    s="abcde";
    n=5;
    call(0);
}