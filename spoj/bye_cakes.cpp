#include<bits/stdc++.h>

using namespace std;

int main(){
    int a[4],b[4],noc;
    while(1){
        for(int i=0; i<4; i++){
            cin>>a[i];
        }
        for(int i=0; i<4; i++){
            cin>>b[i];
        }
        if(a[0]==-1)break;
        noc = 0;
        for(int i=0; i<4; i++){
            noc = max(noc,(a[i]+b[i]-1)/b[i]);
        }
        for(int i=0; i<4; i++){
            cout<<noc*b[i]-a[i]<<" ";
        }
        cout<<"\n";
    }
}