#include<bits/stdc++.h>

using namespace std;

int const lmt = 100;

int n;
int sol[lmt][lmt];
int col[lmt],d1[lmt],d2[lmt];
int cnt=0;
void row(int i){
    if(i==n){
        cnt++;
        cout<<"got a solution!\n";
        for(int x=0; x<n; x++){
            for(int y=0; y<n; y++){
                cout<<sol[x][y]<<" ";
            }cout<<"\n";
        }

        return;
    }
    for(int j=0; j<n; j++){
        if(col[j] || d1[i+j] || d2[n-i+j]) continue;

        sol[i][j]=1;
        col[j] = d1[i+j] = d2[n-i+j]=1;
        row(i+1);
        sol[i][j]=0;
        col[j] = d1[i+j] = d2[n-i+j]=0;
    }
}

int main(){
    cin>>n;
    row(0);
    cout<<cnt<<"\n";
}
