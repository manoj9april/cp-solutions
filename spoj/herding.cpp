#include<bits/stdc++.h>

using namespace std;


int r,c;
bool visited[1001][1001];
char arr[1001][1001];

bool point(int x, int y){
    if(x>=0 && y>=0 && x<r && y<c) return true;

    return false;
}

void dfs(int x, int y){
    if(visited[x][y]) return;
    visited[x][y]=true;

    if(arr[x][y]=='N'){
        dfs(x-1,y);
    }
    else if(arr[x][y]=='S'){
        dfs(x+1,y);
    }
    else if(arr[x][y]=='W'){
        dfs(x,y-1);
    }
    else if(arr[x][y]=='E'){
        dfs(x,y+1);
    }

    if(point(x+1,y) && !visited[x+1][y] && arr[x+1][y]=='N'){
        dfs(x+1,y);
    }
    if(point(x-1,y) && !visited[x-1][y] && arr[x-1][y]=='S'){
        dfs(x-1,y);
    }
    if(point(x,y-1) && !visited[x][y-1] && arr[x][y-1]=='E'){
        dfs(x,y-1);
    }
    if(point(x,y+1) && !visited[x][y+1] && arr[x][y+1]=='W'){
        dfs(x,y+1);
    }

}



int main(){
    cin>>r>>c;

    memset(visited, false, sizeof visited);
    string str;
    for(int i=0; i<r; i++){
        cin>>str;
        for(int j=0; j<c; j++){
            arr[i][j] = str[j];
        }
    }

    int cnt=0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(!visited[i][j]){
                dfs(i,j);
                cnt++;
            }
        }
    }

    cout<<cnt<<endl;

}