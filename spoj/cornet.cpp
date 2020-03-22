#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+1;

int dist[lmt];
int root[lmt]; 

int find(int i){

    if(i!=root[i]){
        int par = root[i];
        root[i] = find(root[i]);
        dist[i] += dist[par];
        return root[i];
    }
    return i;
}

void unio(int a, int b){
    if(find(a)!=find(b)){
        root[a]=b;
    }
    dist[a] = abs(a-b)%1000;
}

int main(){
    int t; cin>>t;

    while(t--){
        int n; cin>>n;
        for(int i=1; i<=n; i++){
            root[i]=i;
            dist[i]=0;
        }
        char q;
        cin>>q;
        int a,b;
        while(q!='O'){
            if(q=='E'){
                cin>>a;
                find(a);
                cout<<dist[a]<<"\n";
            }else if(q=='I'){
                cin>>a>>b;
                unio(a,b);
            }

            cin>>q;
        }
    }

    return 0;
}