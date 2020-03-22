#include<bits/stdc++.h>

using namespace std;

int main(){
    map<string,int> mp;
    string s[6] = {"Power","Time","Space","Soul","Reality","Mind"};
    string cl[6]= {"purple","green","blue","orange","red","yellow"};

    for(int i=0; i<6; i++){
        mp[cl[i]]=i;
    }
    bool check[6];
    memset(check, false, sizeof check);
    int n; cin>>n;
    string clr;
    for(int i=0; i<n; i++){
        cin>>clr;
        check[mp[clr]]=true;
    }
    int cnt=0;
    for(int i=0; i<6; i++){
        if(!check[i])cnt++;
    }
    cout<<cnt<<"\n";

    for(int i=0; i<6; i++){
        if(!check[i]){
            cout<<s[i]<<"\n";
        }
    }
}