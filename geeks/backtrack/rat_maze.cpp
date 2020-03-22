#include<bits/stdc++.h>

using namespace std;

int const lmt=8;
int n;

int kx[2] = {0,1};
int ky[2] = {1,0};
int arr[lmt][lmt];
int sol[lmt][lmt];

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n && arr[x][y]==1) return true;

    return false;
}

bool call(int cx, int cy){
    if(cx==n-1 && cy==n-1){
        cout<<"one solution got!\n";
        sol[cx][cy]=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<sol[i][j]<<" ";
            }cout<<"\n";
        }
        sol[cx][cy]=0;
        return true;
    }

    //arr[cx][cy]=0;
    sol[cx][cy]=1;
    for(int i=0; i<2; i++){
        int x = cx + kx[i];
        int y = cy + ky[i];

        if(check(x,y)){
            if(call(x,y)) return true;
        }
    }
    sol[cx][cy]=0;
    //arr[cx][cy]=1;

    return false;
}

int main(){

    cin>>n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
    }
    
    if(!call(0,0)){
        cout<<"got no solution\n";
    }
}