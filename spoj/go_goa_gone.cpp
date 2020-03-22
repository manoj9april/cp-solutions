#inlcude<bits/stdc++.h>

using namespace std;

vector<int>  adj[9];
bool take[9];

int fun(int g){
    take[g]=false;
    for(int e: adj[g]){
        take[e]=false;
    }
    bool avl=false;
    for(int i=1; i<=8; i++){
        if(take[i]){
            avl=true;
            break;
        }
    }
    if(!avl){
        return a[g];
    }
    int ans = 0;
    for(int i=1; i<=8; i++){
        if(take[i]){
            ans = max(ans,fun(i));
            for(int ei: adj[i])  take[ei]=true;
        }
    }

    
}

int main()
{
    int i,a[9],p;
    for(i=1;i<=8;i++)
    cin>>a[i];
    cin>>p;
    int a,b;
    for(i=0;i<p;i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans =0;
    for(int i=1; i<=8; i++){
        memset(take, true, sizeof take);
        ans = max(ans,fun(i));
    }
}
