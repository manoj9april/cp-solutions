#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[103][103],b[103][103],d[103][103];
int ix[8]={-1,-1,0,1,1,1,0,-1};
int iy[8]={0,1,1,1,0,-1,-1,-1};

bool valid(int i, int j){
    if(i>=0 && i<n && j>=0 && j<m)return true;
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>a[i][j];
        }
    }
    a[0][0]=0;
    int mx=0,dist=INT_MAX;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int nx,ny,cnt=0;
            if(a[i][j]==0)continue;
            for(int k=0; k<8; k++){
                nx=i+ix[k];
                ny=j+iy[k];
                if(valid(nx,ny) && a[nx][ny]) cnt++;
            }
            b[i][j]=cnt;
            d[i][j]=max(i,j);
            //dist = min(d[i][j],dist);
            if(cnt>=mx ){
                mx=cnt;
            }
        }
    }
    if(mx==0){
        cout<<"No suitable girl found";
        return 0;
    }
    cout<<mx<<"\n";

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(b[i][j]==mx ){
                dist = min(dist,max(i,j));
                d[i][j]=max(i,j);
            }
        }
    }

    int cnt=0,idi=-2,idj=-2;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==0)continue;
            if(b[i][j]==mx && d[i][j]==dist){
                cnt++;
                idi=i;idj=j;
            }
        }
    }
    if(cnt>1){
        cout<<"Polygamy not allowed";
    }else{
        cout<<(idi+1)<<":"<<(idj+1)<<":"<<mx;
    }
}