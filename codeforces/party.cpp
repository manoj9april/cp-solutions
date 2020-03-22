#include<bits/stdc++.h>

using namespace std;

#define pb   push_back

vector<int > adj[2005];

int height(int p){
    int ht=0;
    for(int c : adj[p]){
        ht = max(ht,height(c));
    }
    return ht+1;
}

int main(){
    int n;  cin>>n;
    
    for(int i=0; i<= n+1; i++){
        adj[i].clear();
    }
    vector <int> root;
    int head;
    for(int i=1; i<=n; i++){
        cin>>head;
        if(head==-1) root.pb(i);
        else adj[head].pb(i);
    }

    int ans=0;
    int nor = root.size();
    for(int i=0; i<nor; i++){
        ans = max(ans , height(root[i])) ;
    }
    cout<<ans;
}