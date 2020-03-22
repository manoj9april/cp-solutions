#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    char a[4][100];
    for(int i=0; i<4; i++)
        for(int j=0; j<n; j++)a[i][j]='.';
    

    if(k<=n-2){
        int kk=k/2;
        int j=1;
        for(;kk;j++){
            a[1][j]='#';
            kk--;
        }
        j=n-2;
        kk = k/2;
        for(;kk;j--){
            a[1][j]='#';
            kk--;
        }
        if(k%2==1)a[1][n/2]='#';
    }else{
        for(int i=1; i<n-1; i++){
            a[1][i]='#';
        }
        k = k-(n-2);
        int kk=k/2;
        int j=1;
        for(;kk;j++){
            a[2][j]='#';
            kk--;
        }
        j=n-2;
        kk = k/2;
        for(;kk;j--){
            a[2][j]='#';
            kk--;
        }
        if(k%2==1)a[2][n/2]='#';

    }
    cout<<"YES\n";
    for(int i=0; i<4; i++){
        for(int j=0; j<n; j++)cout<<a[i][j];
        cout<<"\n";
    }
}