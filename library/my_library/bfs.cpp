
q.push(0);
vis[0]=1;
dist[0]=0;
while(!q.empty()){
    int p = q.front(); q.pop();

    for(int c: adj[p]){
        if(!vis[c]){
            vis[c]=1;
            dist[c] = dist[p]+1;
            q.push(c);
        }
    }
}