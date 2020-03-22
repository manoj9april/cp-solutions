#include<bits/stdc++.h>

using namespace std;

int const lmt =1e5+6;
int col[lmt];

int main(){
    int n; cin>>n;
    cout<<(n>2?2:1)<<"\n";
    //cout<<(n+1)/2<<"\n";
    
    for(int i=2; i<=n+1; i++){
        if(col[i]==0){
            col[i]=1;
            for(int j=2*i; j<=n+1; j+=i){
                col[j]=2;
            }
        }
    }

    for(int i=2; i<=n+1; i++ ){
        cout<<col[i]<<" ";
    }
    cout<<"\n";

}