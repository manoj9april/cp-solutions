#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int const lmt=16;
ll a[lmt][lmt],vis[lmt][lmt];

int odx[6] = {-1,1,0,0,1,1};
int ody[6] = {0,0,-1,1,-1,1};

int edx[6] = {-1,1,0,0,-1,-1};
int edy[6] = {0,0,-1,1,-1,1};

int codx[6] = {0,0,1,1,1,-1};
int cody[6] = {-1,1,0,-1,1,0};

int cedx[6] = {0,0,-1,-1,-1,1};
int cedy[6] = {-1,1,0,1,-1,0};
int n,m;

ll ans=0;

bool valid(int x, int y){
    if(x<0 || x>=n || y<0 || y>= m || vis[x][y])return 0;
    return 1;
}

void dfs(int x, int y, int sum, int l){
    if(!valid(x,y))return;
    if(l==4){
        ans = max(ans, 1ll*sum + a[x][y]);
    }
    vis[x][y]=1;
    sum += a[x][y];
    if(y&1){
        for(int k=0; k<6; k++){
            int nx = x+odx[k];
            int ny = y+ody[k];
            dfs(nx,ny,sum , l+1); 
        }
    }else{
        for(int k=0; k<6; k++){
            int nx = x+edx[k];
            int ny = y+edy[k];
            dfs(nx,ny,sum ,l+1); 
        }
    }
    vis[x][y]=0;
}

void check(int x, int y){
    // cout<<x<<" "<<y<<"====>\n";
    ll sum=a[x][y];
    if(y&1){
        for(int k=0; k<3; k++){
            // cout<<"*";
            int nx = x+codx[k];
            int ny = y+cody[k];
            // cout<<nx<<" "<<ny<<"\n";
            if(valid(nx,ny)) sum += a[nx][ny];
            else return; 
        }
    }else{
        for(int k=0; k<3; k++){
            // cout<<"*";
            int nx = x+cedx[k];
            int ny = y+cedy[k];
            // cout<<nx<<" "<<ny<<"\n";
            if(valid(nx,ny)) sum += a[nx][ny];
            else return; 
        }
    }
    // cout<<sum<<"\n";
    ans = max(sum,ans);
}

void check2(int x, int y){
    // cout<<x<<" "<<y<<"====>\n";
    ll sum=a[x][y];
    if(y&1){
        for(int k=0; k<3; k++){
            // cout<<"*";
            int nx = x+codx[k+3];
            int ny = y+cody[k+3];
            // cout<<nx<<" "<<ny<<"\n";
            if(valid(nx,ny)) sum += a[nx][ny];
            else return; 
        }
    }else{
        for(int k=0; k<3; k++){
            // cout<<"*";
            int nx = x+cedx[k+3];
            int ny = y+cedy[k+3];
            // cout<<nx<<" "<<ny<<"\n";
            if(valid(nx,ny)) sum += a[nx][ny];
            else return; 
        }
    }
    // cout<<sum<<"\n";
    ans = max(sum,ans);
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n>>m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) cin>>a[i][j];
        }
        ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) dfs(i,j,0,1);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) check2(i,j);
        }
        check(1,2);
        cout<<ans<<"\n";
    }
}
