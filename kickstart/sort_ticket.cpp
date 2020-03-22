#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("sort_ticket.in","r",stdin);
    freopen("sort_ticket.out","w",stdout);
    int t; cin>>t;
    int tt=1;
    while(t--){
        int n; cin>>n;

        map<string,string> next,prev;

        string from,to,st,city[n];
        for(int i=0; i<n; i++){
            cin>>from>>to;
            city[i]=from;
            next[from]=to;
            prev[to]=from;
        }

        for(int i=0; i<n; i++){
            if(prev[city[i]]==""){
                st=city[i];
            }
        }
        cout<<"Case #"<<tt<<": ";
        for(int i=0; i<n; i++){
            cout<<st<<"-"<<next[st]<<" ";
            st = next[st];
        }

        cout<<"\n"; tt++;
    }
}