#include<bits/stdc++.h>

using namespace std;

int kx[8]={-2,-1,1,2,2,1,-1,-2};
int ky[8]={1,2,2,1,-1,-2,-2,-1};

int vis[10][10];

bool check(int x, int y){
    if(x>=0 && y>=0 && x<10 && y<10) return true;

    return false;
}
int N;
void call(int x,int y,int n){
    if(n==N) return;
    for(int i=0; i<8; i++){
        int nx = x+kx[i];
        int ny = y+ky[i];
        if(check(nx,ny) && vis[nx][ny]>n+1){
            vis[nx][ny]=n+1;
            call(nx,ny,n+1);
        } 
    }
}

int main(){
    int x,y;
    cin>>x>>y>>N;
    x--;y--;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            vis[i][j]=12;
        }
    }
    call(x,y,0);
    int cnt=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            if(vis[i][j] !=12) cnt++;
            //cout<<vis[i][j]<<" ";
        }//cout<<endl;
    }

    cout<<cnt<<"\n";
}