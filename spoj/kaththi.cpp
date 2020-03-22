#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define mp make_pair
#define pb push_back
#define F first
#define S second


bool visited[1005][1005];
int dist[1005][1005];
char arr[1005][1005];
int r,c;

bool point(int x, int y){
    if(x>=0 && y>=0 && x<r && y<c) return true;

    return false;
}

void djk(int x, int y)
{
    deque<pair <pair<int, int> > q;   // distance from v1 or dist[node] ,  node
    dist[x][y] = 0;
    q.insert(mp(0, mp(x,y)));  // or q.insert(mp( dist[x][y],(x,y) ));

    while (!q.empty())
    {
        pair<int, pair<int, int> > p = *q.begin();
        q.erase(q.begin());
	
        x=p.S.F;
        y=p.S.S;

        if(visited[r-1][c-1]) break;

        if(!visited[x][y]){
            
            if(point(x+1,y)){
                if(arr[x+1][y]==arr[x][y]){
                    if(dist[x][y] < dist[x+1][y]){
                        dist[x+1][y] = dist[x][y];
                        q.insert(mp(dist[x+1][y], mp(x+1,y)));
                    }
                }
                else if(dist[x][y] +1 < dist[x+1][y]){
                    dist[x+1][y] = dist[x][y] +1;
                    q.insert(mp(dist[x+1][y], mp(x+1,y)));
                }
            }
            if(point(x-1,y) ){
                if(arr[x-1][y]==arr[x][y]){
                    if(dist[x][y] < dist[x-1][y]){
                        dist[x-1][y] = dist[x][y];
                        q.insert(mp(dist[x-1][y], mp(x-1,y)));
                    }
                }
                else if(dist[x][y] +1 < dist[x-1][y]){
                    dist[x-1][y] = dist[x][y]+1;
                    q.insert(mp(dist[x-1][y], mp(x-1,y)));
                }
            }
            if(point(x,y-1) ){
                if(arr[x][y-1]==arr[x][y]){
                    if(dist[x][y] < dist[x][y-1]){
                        dist[x][y-1] = dist[x][y];
                        q.insert(mp(dist[x][y-1], mp(x,y-1)));
                    }
                }
                else if(dist[x][y] +1< dist[x][y-1]){
                    dist[x][y-1] = dist[x][y]+1;
                    q.insert(mp(dist[x][y-1], mp(x,y-1)));
                }
            }
            if(point(x,y+1) ){
                if(arr[x][y+1]==arr[x][y]){
                    if(dist[x][y] < dist[x][y+1]){
                        dist[x][y+1] = dist[x][y];
                        q.insert(mp(dist[x][y+1], mp(x,y+1)));
                    }
                }
                else if(dist[x][y] +1< dist[x][y+1]){
                    dist[x][y+1] = dist[x][y]+1;
                    q.insert(mp(dist[x][y+1], mp(x,y+1)));
                }
            }

            visited[x][y]=true;
        
        }
    }
}

int main(){
    
    int t; scanf("%d",&t);
    //cin>>t;
    while(t--){

        //cin>>r>>c;
        scanf("%d%d",&r,&c);

        memset(visited, false, sizeof visited);
        memset(dist, 1000008, sizeof dist);
        string str;
        for(int i=0; i<r; i++){
            //cin>>str;
            scanf("%s",arr[i]);
            
            /*for(int j=0; j<c; j++){
                arr[i][j] = str[j];
            }*/
        }

        djk(0,0);

        //cout<<dist[r-1][c-1]<<endl;
        printf("%d\n",dist[r-1][c-1]);
    }
}