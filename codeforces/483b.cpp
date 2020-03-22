#include<bits/stdc++.h>

using namespace std;

int kx[8]={-1,-1,-1,0,1,1,1,0};
int ky[8]={-1,0,1,1,1,0,-1,-1};


int n,m;

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n && y<m) return true;

    return false;
}

int main(){

    cin>>n>>m;

    int a[n][m]={0},sol[n][m]={0};
    memset(a,0,sizeof a);
    memset(sol,0,sizeof sol);
    char ch;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>ch;
            if(ch=='.'){
                a[i][j]=0;
            }else if(ch=='*'){
                a[i][j]=-1;
                for(int g=0; g<8; g++){
                    if(check(i+kx[g],j+ky[g]))
                        sol[i+kx[g]][j+ky[g]]++;
                }
            }else{
                a[i][j]=ch-'0';
            }
        }
    }

    bool ok=true;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(a[i][j]==-1) continue;
            if(a[i][j]!=sol[i][j]){
                ok=false;
                break;
            }
        }
        if(!ok)break;
    }

    cout<<(ok?"YES":"NO")<<"\n";
}