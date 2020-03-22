#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair< ll, pair<int, int> >  plii;
int const lmt=1e5+1;

int size[lmt];
int root[lmt];

int find(int i){
    if(root[i]!=i){
        return root[i] = find(root[i]);
    }
    return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        int arr[n+1];

        for(int i=1; i<=n; i++){
            cin>>arr[i];
            size[i]=1;
            root[i]=i;
        }

        plii edge[m];
        for(int i=0; i<m; i++){
            cin>>edge[i].second.first>>edge[i].second.second;
            cin>>edge[i].first;
        }

        sort(edge, edge+m);

        ll ans=0;
        for(int i=0; i<m; i++){
            int a = edge[i].second.first;
            int b = edge[i].second.second;
            ll ct = edge[i].first;

            int x= find(a);
            int y = find(b);

            if(arr[x]==1 && arr[y]==1) continue;
            if(x!=y){
                ans += ct;
                if(arr[x]==0 && arr[y]==0){
                    if(size[x]>size[y]){
                        size[x]+=size[y];
                        size[y]=0;
                        root[y]=x;
                    }else{
                        size[y]+=size[x];
                        size[x]=0;
                        root[x]=y;
                    }
                }else if(arr[x]==1){
                    size[x]+=size[y];
                    size[y]=0;
                    root[y]=x;
                }else{
                    size[y]+=size[x];
                    size[x]=0;
                    root[x]=y;
                }
            }
        }

        bool ok=true;
        int k=0,l=0;
        for(int i=1; i<=n; i++){
            if(size[i]==0) k++;
            if(arr[i]==0) l++;
        }

        //cout<<ans<<'\n';
        if(k==l){
            cout<<ans<<"\n";
        }else{
            cout<<"impossible\n";
        }
    }
}