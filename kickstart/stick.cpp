#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int const lmt =20; 

vector<pii> adj[lmt]; // child , el

int main(){
    int t; cin>>t;
    int tt=1;
    while(t--){
        int n; cin>>n;
        int el;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                cin>>el;
                if(el!=0){
                    adj[i].push_back(make_pair(j,el));
                }
            }
        }

        for(int i=0;)
    }
}