#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
typedef long long int ll;
typedef unsigned long long int  ull;


struct node{
    ll all,his,even,odd;
};
int const lmt = 1e5+4;

vector<int> adj[lmt];
node  val[lmt];

void dfs(int p){

    for(int i=0; i<adj[p].size(); i++){
        int c = adj[p][i];
        val[c].all += val[p].all;
        val[c].even += val[p].even;
        val[c].odd += val[p].odd;
        dfs(c);
    }
}

int main(){
    int n,q;
    cin>>n>>q;
    int sr;
    for(int i=2; i<=n; i++){
        cin>>sr;
        adj[sr].pb(i);
    }

    int ty,fr,nos;
    while(q--){
        cin>>ty>>fr>>nos;
        if(ty==1){
            val[fr].all += nos;
        }else{
            if(fr%2==0) val[fr].odd += nos;
            else  val[fr].even += nos;

            val[fr].his += nos;
        }
    }

    dfs(1);

    ll mx=0,ttl;int idx=1;
    for(int i=1; i<=n; i++){
        if(i%2==0){
            ttl = val[i].all+val[i].even+val[i].his;
            if(ttl>mx){
                mx=ttl;
                idx=i;
            }
        }else{
            ttl = val[i].all+val[i].his+val[i].odd;
            if(ttl>mx){
                mx=ttl;
                idx=i;
            }
        }
        
    }

    cout<<idx<<" "<<mx<<"\n";
}