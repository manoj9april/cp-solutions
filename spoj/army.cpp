#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>> t;

    while(t--){
        int ng,nm,gm=0,mm=0,ele;; cin>>ng>>nm;
        for(int i=0; i<ng; i++){
            cin>>ele;
            if(ele>gm) gm=ele;
        }

        for(int i=0; i<nm; i++){
            cin>>ele;
            if(ele>mm) mm=ele;
        }
        cout<<(mm>gm?"MechaGodzilla":"Godzilla")<<endl;
    }
}