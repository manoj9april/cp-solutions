#include<bits/stdc++.h>

using namespace std;

int main(){
    freopen("gbus_large.in","r",stdin);
    freopen("gbus_large.out","w",stdout);

    int t; cin>>t;
    int tt=1;
    while(t--){
        int n; cin>>n;
        
        int city[5002];
        memset(city,0,sizeof city);

        int a,b;
        for(int i=1; i<=n; i++){
            cin>>a>>b;
            city[a]++;
            city[b+1]--;
        }

        for(int i=1; i<=5000; i++){
            city[i] += city[i-1];
        }

        int p; cin>>p;

        cout<<"Case #"<<tt<<": ";
        int ct;
        while(p--){
            cin>>ct;
            cout<<city[ct]<<" ";
        }
        cout<<"\n";
        tt++;
    }
}



