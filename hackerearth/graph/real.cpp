#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e4+6;

bool nod[lmt];

int main(){
    int t,e,a,b; cin>>t;
    while(t--){
        cin>>e;
        memset(nod, false, sizeof nod);
        for(int i=0; i<e; i++){
            cin>>a>>b;
            nod[a]=true;
            nod[b]=true;
        }
        int cnt=0;
        for(int i=1; i<= lmt; i++)if(nod[i])cnt++;
        cout<<cnt<<"\n";
    }
}