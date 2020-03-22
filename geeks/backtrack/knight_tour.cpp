#include<bits/stdc++.h>

using namespace std;

int const n=8;

int kx[n] = {-1,-2,-2,-1,1,2,2,1};
int ky[n] = {-2,-1,1,2,2,1,-1,-2};
int arr[n][n];

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n && arr[x][y]==-1) return true;

    return false;
}

bool call(int cx, int cy, int mno){
    if(mno==n*n-1){
        cout<<"one solution got!\n";
        arr[cx][cy]=mno;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }cout<<"\n";
        }
        return true;
    }

    arr[cx][cy]=mno;

    for(int i=0; i<8; i++){
        int x = cx + kx[i];
        int y = cy + ky[i];

        if(check(x,y)){
            if(call(x,y,mno+1)) return true;
        }
    }

    arr[cx][cy]=-1;

    return false;
}

int main(){
    memset(arr, -1, sizeof arr);
    call(0,0,0);
    return 0;
    if(!call(0,0,0)){
        cout<<"got no solution\n";
    }
}