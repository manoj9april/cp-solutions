#include<bits/stdc++.h>

using namespace std;

int kx[] = {-1,-1,-1,0,1,1,1,0};
int ky[] = {-1,0,1,1,1,0,-1,-1};

string g[101];
string test="ALLIZZWELL";
int r,c;

bool vis[101][101];

bool check(int x, int y){
    if(x>=0 && y>=0 && x<r && y<c) return true;

    return false;
}

bool dfs(int x, int y, int idx){

    if(idx==9) return true;

    for(int i=0; i<8; i++){
        int cx = x + kx[i];
        int cy = y + ky[i];
        if(!vis[cx][cy]){
            vis[cx][cy]=true;
            if(check(cx,cy) && g[cx][cy]==test[idx+1] && dfs(cx,cy,idx+1)) return true;
            vis[cx][cy]=false;
        }
    }

    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=0; i<r; i++){
            cin>>g[i];
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                memset(vis,false, sizeof vis);
                vis[i][j]=true;
                if(g[i][j]=='A' && dfs(i,j,0)){
                    cout<<"YES\n";
                    goto label;
                }
            }
        }

        cout<<"NO\n";

        label:  
        int d;
    }
}