#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int r,c;
bool vis[1001][1001];
int ans[1001][1001];
bool point(int x, int y){
	if(x<0 || y<0 || x>=r || y>=c) return false;
	return true;
}
int maxp,maxi,maxj;
void dfs(int x,int y){
    vis[x][y]=true;
    if(point(x-1,y) && !vis[x-1][y]){
        ans[x-1][y]=ans[x][y]+1;
        if(ans[x-1][y]>maxp){
            maxi=x-1;
            maxj=y;
        }
        dfs(x-1,y);
    }
    if(point(x+1,y) && !vis[x+1][y]){
        ans[x+1][y]=ans[x][y]+1;
        if(ans[x+1][y]>maxp){
            maxi=x+1;
            maxj=y;
        }
        dfs(x+1,y);
    }
    if(point(x,y-1) && !vis[x][y-1]){
        ans[x][y-1]=ans[x][y]+1;
        if(ans[x][y-1]>maxp){
            maxi=x;
            maxj=y-1;
        }
        dfs(x,y-1);
    }
    if(point(x,y+1) && !vis[x][y+1]){
        ans[x][y+1]=ans[x][y]+1;
        if(ans[x][y+1]>maxp){
            maxi=x;
            maxj=y+1;
        }
        dfs(x,y+1);
    }
}


int main(){
    int t; cin>>t;
    while(t--){
        cin>>c>>r;
        char lab[r][c];
        for(int i=0; i<r; i++){
            string s; cin>>s;
            for(int j=0; j<c; j++){
                lab[i][j]=s[j];
            }
        }
        memset(vis,false,sizeof vis);
        for(int i=0; i<r; i++){
            string s; cin>>s;
            for(int j=0; j<c; j++){
                if(lab[i][j]=='.' && !vis[i][j]){
                    ans[i][j]=0;
                    dfs(i,j);
                    memset(vis,false,sizeof vis);
                    dfs(maxi,maxj);
                }
            }
        }
        cout<<maxp<<endl;
    }
}