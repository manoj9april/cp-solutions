#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

#define mp  make_pair
#define pb  push_back
#define pf  push_front
#define ft   first
#define sec   second

int dist[1001][1001];

string g[1001];
int r,c;

bool check(int x, int y){
    if(x>=0 && x<r && y>=0 && y<c) return true;

    return false;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>r>>c;
        for(int i=0; i<r; i++){
            cin>>g[i];
        }

        memset(dist, 1000008, sizeof dist);
        deque<pii> q;
        q.pf(mp(0,0));
        dist[0][0]=0;
        while(!q.empty()){
            pii p = q.front();  q.pop_front();
            int x = p.first; int y = p.second;
            if(check(x-1,y)){  // upper
                if(g[x-1][y]==g[x][y]){
                    if(dist[x-1][y]>dist[x][y]){
                        q.pf(mp(x-1,y));
                        dist[x-1][y]=dist[x][y];
                    }
                }else{
                    if(dist[x-1][y]>dist[x][y]+1){
                        q.pb(mp(x-1,y));
                        dist[x-1][y]=dist[x][y]+1;
                    }
                }
            }


            if(check(x+1,y)){ // lower
                if(g[x+1][y]==g[x][y]){
                    if(dist[x+1][y]>dist[x][y]){
                        q.pf(mp(x+1,y));
                        dist[x+1][y]=dist[x][y];
                    }
                }else{
                    if(dist[x+1][y]>dist[x][y]+1){
                        q.pb(mp(x+1,y));
                        dist[x+1][y]=dist[x][y]+1;
                    }
                }
            }

            if(check(x,y-1)){  // left
                if(g[x][y-1]==g[x][y]){
                    if(dist[x][y-1]>dist[x][y]){
                        q.pf(mp(x,y-1));
                        dist[x][y-1]=dist[x][y];
                    }
                }else{
                    if(dist[x][y-1]>dist[x][y]+1){
                        q.pb(mp(x,y-1));
                        dist[x][y-1]=dist[x][y]+1;
                    }
                }
            }

            if(check(x,y+1)){  // right
                if(g[x][y+1]==g[x][y]){
                    if(dist[x][y+1]>dist[x][y]){
                        q.pf(mp(x,y+1));
                        dist[x][y+1]=dist[x][y];
                    }
                }else{
                    if(dist[x][y+1]>dist[x][y]+1){
                        q.pb(mp(x,y+1));
                        dist[x][y+1]=dist[x][y]+1;
                    }
                }
            }
        }
        
        cout<<dist[r-1][c-1]<<"\n";
    }
}