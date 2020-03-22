#include<bits/stdc++.h>
#include <iostream>
using namespace std;


int r,c;
int a[1001][1001];
bool res[1001][1001];

bool point(int x, int y){
	if(x>=0 && y>=0 && x<r && y<c && a[x][y]!=-2) return true;
	return false;
}

int main() {
	// your code goes here
	int t;cin>>t;
	
	while(t--){
        queue<pair<int,int> > q;
		cin>>r>>c;
        memset(res,false,sizeof(res));
		
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
				cin>>a[i][j];
                if(a[i][j]>0){
					q.push(make_pair(i,j));
                    res[i][j]=true;
				}
                if(a[i][j]<=0) a[i][j]--;
			}
		}

        pair<int, int> p;
        while(!q.empty()){
            p = q.front(); q.pop();
            //if(ans[p.x][p.y]>=time) continue;
            int x =p.first; int y=p.second;
            if(point(x-1,y) && a[x-1][y]<a[x][y]-1){
                q.push(make_pair(x-1,y));
                a[x-1][y]=a[x][y]-1;
                //ans[x-1][y]=ans[x][y]+1;
                res[x-1][y]=true;
            }
            if(point(x+1,y) && a[x+1][y]<a[x][y]-1){
                q.push(make_pair(x+1,y));
                a[x+1][y]=a[x][y]-1;
                //ans[x+1][y]=ans[x][y]+1;res
                res[x+1][y]=true;
            }
            if(point(x,y-1) && a[x][y-1]<a[x][y]-1){
                a[x][y-1]=a[x][y]-1;
                q.push(make_pair(x,y-1));
                //ans[x][y-1]=ans[x][y]+1;
                res[x][y-1]=true;
            }
            if(point(x,y+1) && a[x][y+1]<a[x][y]-1){
                a[x][y+1]=a[x][y]-1;
                q.push(make_pair(x,y+1));
                //ans[x][y+1]=ans[x][y]+1;
                res[x][y+1]=true;
            }
        }
        //cout<<"\n\n";
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
                if(a[i][j]==-2)cout<<"B";
                else
                    cout<<(a[i][j]>=0?"Y":"N");   
            }
			cout<<"\n";
		}
        /*
        for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
                cout<<a[i][j]<<" ";
            }
			cout<<endl;
		}
		*/
	}
	return 0;
}