#include<bits/stdc++.h>

# define MM 1000008

using namespace std;

bool vis[MM];
vector<int> adj[MM];

// max height of tree (returns max no. of nodes)

long long int height(int root){
    vis[root]=true;

    long long int max_c_h=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            max_c_h = max(height(child),max_c_h);
        }
    }

    return max_c_h+1;
}

// diameter of tree  (returns no. of nodes in diameter)

long long int diameter(int root){
    vis[root]=true;

    long long int max_c_h=0;
    long long int smax_c_h=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            int h = height(child);
            if(h>= max_c_h){
                smax_c_h = max_c_h;
                max_c_h = h;
                
            }
        }
    }

    long long int max_c_d=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            max_c_d = max(diameter(child),max_c_d);
        }
    }

    return max(max_c_d,(max_c_h + smax_c_h + 1));

}

int main(){
    int t; cin>>t;
    while(t--){
        int r,c;
        cin>>c>>r;

        bool gr[r][c];
        memset(gr,false,sizeof(gr));

        memset(vis,false,sizeof(vis));

        for(int i=0; i<MM; i++){
            adj[i].clear();
        }


        char ch;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cin>>ch;
                if(ch=='.') gr[i][j]=true;
            }
        }

        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(!gr[i][j]) continue;
                int index = i*c + j;
                if(i-1>=0 && gr[i-1][j]){
                    int nind = (i-1)*c + j;
                    adj[index].push_back(nind);
                }
                if(j+1<c && gr[i][j+1]){
                    int nind = (i)*c + j+1;
                    adj[index].push_back(nind);
                }
                if(i+1<r && gr[i+1][j]){
                    int nind = (i+1)*c + j;
                    adj[index].push_back(nind);
                }
                if(j-1>=0 && gr[i][j-1]){
                    int nind = (i)*c + j-1;
                    adj[index].push_back(nind);
                }
            }
        }

        /*int totalnodes = r*c;
        int maxd = -1;
        for(int i=0; i<totalnodes; i++){
            if(!vis[i]){
                maxd = max(maxd, diameter(i));
            }
        }*/

        long long int maxd = -1;
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                if(gr[i][j]){
                    int index = i*c + j;
                    if(!vis[index]){
                        maxd = max(maxd, diameter(index));
                    }
                }
            }
        }
        

        cout<<"Maximum rope length is "<<maxd-1<<".\n";
    }
}