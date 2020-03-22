#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>  pii;
#define  mp  make_pair
#define f  first
#define  s  second

int r,c;
bool vis[100+1][100+1];
int c1[100+1][100+1], c2[100+1][100+1], m[100+1][100+1];


bool point(int x, int y){
    if(x>=1 && y>=1 && x<=r && y<=c) return true;

    return false;
}

void bfs(int x, int y, int dist[101][100+1]){
    queue<pii>  q;

    q.push(mp(x,y));
    vis[x][y]=true;
    while(!q.empty()){
        pii  p = q.front(); q.pop();
        x = p.f;
        y = p.s;

        if(point(x+1,y) && !vis[x+1][y]){
            q.push(mp(x+1,y));
            dist[x+1][y]=dist[x][y]+1;
            vis[x+1][y]=true;
        }
        if(point(x-1,y) && !vis[x-1][y]){
            q.push(mp(x-1,y));
            dist[x-1][y]=dist[x][y]+1;
            vis[x-1][y]=true;
        }
        if(point(x,y+1) && !vis[x][y+1]){
            q.push(mp(x,y+1));
            dist[x][y+1]=dist[x][y]+1;
            vis[x][y+1]=true;
        }
        if(point(x,y-1) && !vis[x][y-1]){
            q.push(mp(x,y-1));
            dist[x][y-1]=dist[x][y]+1;
            vis[x][y-1]=true;
        }
    }
}

int main(){
    cin>>r>>c;
    
    int t; cin>>t;
    while(t--){
        int mx,my,c1x,c1y, c2y, c2x;
        cin>>mx>>my>>c1x>>c1y>>c2x>>c2y;

        memset(vis,false, sizeof vis);
        vis[mx][my]=true;
        m[mx][my]=0;
        bfs(mx,my,m);

        memset(vis,false, sizeof vis);
        vis[c1x][c1y]=true;
        c1[c1x][c1y]=0;
        bfs(c1x,c1y,c1);

        memset(vis,false, sizeof vis);
        vis[c2x][c2y]=true;
        c2[c2x][c2y]=0;
        bfs(c2x,c2y,c2);

        bool mout=false;
        for(int i=1; i<=r; i++){
            for(int j=1;j<=c; j++){
                if(i==1|| i==r|| j==1|| j==c){
                    if(m[i][j]<c1[i][j] && m[i][j]<c2[i][j]){
                        cout<<"YES\n";
                        mout=true;
                        break;
                    }
                }
            }
            if(mout) break;
        }

        if(!mout) cout<<"NO\n";
    }
}