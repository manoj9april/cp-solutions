#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int>  pii;
#define  mp  make_pair
#define f  first
#define  s  second

int r,c;
int X,Y;

bool point(int x, int y){
    if(x>=0 && y>=0 && x<r && y<c) return true;

    return false;
}
char graph[22][22];
bool vis[22][22];

bool bfs(int x, int y){
    queue<pii>  q;

    q.push(mp(x,y));
    vis[x][y]=true;
    while(!q.empty()){
        pii  p = q.front(); q.pop();
        x = p.f;
        y = p.s;

        if(point(x+1,y) && !vis[x+1][y]){
            q.push(mp(x+1,y));
            if(x+1==X && y==Y){
                return true;
            }
            vis[x+1][y]=true;
        }
        if(point(x-1,y) && !vis[x-1][y]){
            q.push(mp(x-1,y));
            if(x-1==X && y==Y){
                return true;
            }
            vis[x-1][y]=true;
        }
        if(point(x,y+1) && !vis[x][y+1]){
            q.push(mp(x,y+1));
            if(x==X && y+1==Y){
                return true;
            }
            vis[x][y+1]=true;
        }
        if(point(x,y-1) && !vis[x][y-1]){
            q.push(mp(x,y-1));
            if(x==X && y-1==Y){
                return true;
            }
            vis[x][y-1]=true;
        }
    }

    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>r>>c;
        string s;
        memset(vis, false , sizeof vis);
        vector<pii>  v;
        for(int i=0; i<r; i++){
            cin>>s;
            for(int j=0; j<c; j++){
                graph[i][j] = s[j];
                if(s[j]=='#'){
                    vis[i][j]=true;
                }else if(i==0 || j==0 || i==r-1 ||j==c-1){
                    v.push_back(mp(i,j));
                }
            }
        }
        if(v.size()==2){
            pii st = v[0];
            pii end = v[1];
            X = end.f; Y=end.s;
            cout<<(bfs(st.f, st.s)?"valid":"invalid")<<endl;
        }else{
            cout<<"invalid\n";
        }
        
    }
}