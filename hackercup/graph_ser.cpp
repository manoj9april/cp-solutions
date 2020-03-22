#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 70,inf=1e18+2;
ll n,m;

ll adj[lmt][lmt],dist[lmt][lmt];
void ini(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            adj[i][j]=0;
            dist[i][j]=inf;
            if(i==j)dist[i][j]=0;
        }
    }
}

bool check(){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(adj[i][j]){
                if(adj[i][j]!=dist[i][j]) return false;
            }
        }
    }

    return true;
}

void printt(){
    cout<<m<<"\n";
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i-1; j++){
            if(adj[i][j]){
                cout<<i<<" "<<j<<" "<<adj[i][j]<<"\n";
            }
        }
    }
}
int main(){
    freopen("../input4.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        cin>>n>>m;
        ll a,b,c;
        ini();

        for(int i=0; i<m; i++){
            cin>>a>>b>>c;
            adj[a][b]=c;
            adj[b][a]=c;
        }   
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(adj[i][j])dist[i][j]=adj[i][j];
            }
        }
        for(int k=1; k<=n; k++){
            for(int i=1; i<=n; i++){
                for(int j=1; j<=n; j++){
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
        ll ans = check();
        //
        cout<<"Case #"<<tt<<": ";
        //
        if(ans) printt();
        else cout<<"Impossible\n";
        //
        // cout<<"\n";
    }
}
