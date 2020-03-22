#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        
    }
}

//
for(int i=0; i<e; i++){
            cin>>v>>nbr;
            nof[v-1].push_back(nbr-1);
            nof[nbr-1].push_back(v-1);
        }


        //
#include<bits/stdc++.h>
 
#define MM 100005
 
using namespace std;
 
//class
bool vis[MM];
vector<int> nof[MM];
 
long long int dfs(int node){
    int cnt=1;
    vis[node]=true;
    for(auto child : nof[node]){
        if(!vis[child]){
            cnt += dfs(child);
        }
        
    }
    return cnt;
}
 
int main(){
    int t; cin>>t; 
    while(t--){
        int n,e,clib,croad;
        cin>>n>>e>>clib>>croad;
        for(int i=0;i<n;i++)
            nof[i].clear();
 
        int v,nbr;
        for(int i=0; i<e; i++){
            cin>>v>>nbr;
            nof[v-1].push_back(nbr-1);
            nof[nbr-1].push_back(v-1);
        }
 
 
        memset(vis,false,sizeof vis);
 
        long long int sum=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
          
                int noc = dfs(i);
                sum += min(noc*clib,(noc-1)*croad + clib);
            }
        }
        cout<<sum<<"\n";
    }
 
}


// max height of tree (returns max no. of nodes)

int height(int root){
    vis[root]=true;

    int max_c_h=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            max_c_h = max(height(child),max_c_h);
        }
    }

    return max_c_h+1;
}

// diameter of tree  (returns no. of nodes in diameter)

int diameter(int root){
    vis[root]=true;

    int max_c_h=0;
    int smax_c_h=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            int h = height(child);
            if(h>= max_c_h){
                max_c_h = h;
                smax_c_h = max_c_h;
            }
        }
    }

    int max_c_d=0;
    for(auto child : adj[root]){
        if(!vis[child]){
            max_c_d = max(diameter(child),max_c_d);
        }
    }

    return max(max_c_d,(max_c_h + smax_c_h + 1));

}

