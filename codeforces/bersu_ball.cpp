#include<bits/stdc++.h>

using namespace std;

int main(){
    int nb,ng;
    cin>>nb;
    int boys[nb];
    for(int i=0; i<nb; i++){
        cin>>boys[i];
    }

    cin>>ng;
    int girls[ng];
    for(int i=0; i<ng; i++){
        cin>>girls[i];
    }

    int pair=0;
    sort(boys,boys+nb);
    sort(girls, girls+ng);
    int b=0,g=0;
    for( ; b<nb && g<ng; ){
        if(abs(boys[b]-girls[g]) <= 1){
            pair++;
            b++; g++;
        }else if(boys[b]<girls[g]) b++;
        else g++;
    }

    cout<<pair<<endl;
}