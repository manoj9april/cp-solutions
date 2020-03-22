#include<bits/stdc++.h>

# define MM 100005

using namespace std;

bool vis[MM];
vector<int> nof[MM];


long long int dfs(int node){
    long long int cnt=1;
    vis[node]=true;
    for(auto child : nof[node]){
        if(!vis[child]){
            cnt += dfs(child);
        }
    }
    return cnt;
}

int main(){
    int n,e; cin>>n>>e;

    for (int i = 0; i < n; i++)
        nof[i].clear();

    int v, nbr;
    for (int i = 0; i < e; i++)
    {
        cin >> v >> nbr;
        nof[v].push_back(nbr);
        nof[nbr].push_back(v);
    }

    vector<long long int> no_node;

    for(int i=0; i<n; i++){
        if(!vis[i]){
            no_node.push_back(dfs(i));
        }
    }

    int len = no_node.size();

    long long a[len];

    memset(a,0,sizeof(a));
    a[0] = no_node[0];
    for(int i=1; i<len; i++){
        a[i] = a[i-1] + no_node[i];
    }

    for(int i=0; i<len; i++){
        a[i] = a[len-1] - a[i];
    }

    long long sum =0;

    for(int i=0; i<len-1; i++ ){
        sum += no_node[i]*a[i];
    }

    cout<<sum;
}