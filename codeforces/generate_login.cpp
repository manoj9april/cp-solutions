#include<bits/stdc++.h>

using namespace std;

int main(){
    string first,last;
    bool l=false;
    cin>>first>>last;
    int l1=first.length();
    int l2 = last.length();

    string login ="";
    login += first[0];

    for(int i=1;i<l1; i++){
        if(last[0]<=first[i]){
            login += last[0];
            l=true;
            break;
        }else{
            login += first[i];
        }
    }

    if(!l){
        login += last[0];
    }
    cout<<login<<endl;
}