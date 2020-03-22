#include<bits/stdc++.h>

using namespace std;

string str[51];
int dis[51][51];
bool vis[51][51];

int kx[8]={-1,-1,-1,0,1,1,1,0};
int ky[8]={-1,0,1,1,1,0,-1,-1};

int n,m;

bool check(int x, int y){
    if(x>=0 && x<n && y>=0 && y<m && !vis[x][y]) return true;
    return false;
}

void dfs(int x,int y){
    vis[x][y]=true;

    for(int i=0; i<8; i++){
        int nx = x+kx[i];
        int ny = y+ky[i];
        if(check(nx,ny) && (int)(str[nx][ny]-'A')==(int)(str[x][y]-'A'+1)){
            dis[nx][ny] = dis[x][y]+1;
            dfs(nx,ny);
        }
    }
}

int main(){
    cin>>n>>m;
    int t=1;
    while(n!=0 && m!=0){
        memset(vis, false, sizeof vis);
        memset(dis, 0, sizeof dis);

        for(int i=0; i<n; i++){
            cin>>str[i];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(str[i][j]=='A'){
                    dis[i][j]=1;
                    dfs(i,j);
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                //cout<<dis[i][j]<<" ";
                if(dis[i][j]>ans){
                    ans=dis[i][j];
                }
            }
            //cout<<endl;
        }
        cout<<"Case "<<t<<": "<<ans<<"\n";
        cin>>n>>m;
        t++;
    }
}