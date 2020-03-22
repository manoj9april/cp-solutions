#include<bits/stdc++.h>

using namespace std;

int r,c;

bool point(int x, int y){
    if(x==0 && y==0)return false;
    if(x>=0 && y>=0 && x<r && y<c) return true;
    return false;
}

int main(){
    c=3;
    int t=1;
    cin>>r;
    while(r){
        int cost[r][c];
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>cost[i][j];
            }
        }
        long long path[r][c];
        path[0][1]=cost[0][1];
        path[0][2]= cost[0][1] + cost[0][2];
        
        for(int i=1; i<r; i++){
            for(int j=0; j<c; j++){
                long long minp = INT_MAX;
                int x=i,y=j;
                if(point(x,y-1)){
                    minp = min(minp,path[x][y-1]);
                }
                if(point(x-1,y)){
                    minp = min(minp,path[x-1][y]);
                }
                if(point(x-1,y-1)){
                    minp = min(minp,path[x-1][y-1]);
                }
                if(point(x-1,y+1)){
                    minp = min(minp,path[x-1][y+1]);
                }
                path[i][j]=cost[i][j];
                if(minp!=INT_MAX){
                    path[i][j] += minp;
                }
            }
        }

        cout<<(t++)<<". "<<path[r-1][1]<<endl;

        cin>>r;
    }
}