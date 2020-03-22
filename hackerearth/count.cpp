#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+1;
int const M = 1e9+7;

int root[lmt];
int size[lmt];
int fc[lmt];
int cnt[lmt];

int find(int i){
    if(root[i]!=i){
        return root[i] = find(root[i]);
    }

    return i;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);  cout.tie(0);
    int n,m;
    cin>>n>>m;
    // ini
    for(int i=1; i<=n; i++){
        size[i]=1;
        cnt[i]=1;
        root[i]=i;
        //cin>>fc[i];
    }
    //cin>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        int x = find(a);
        int y = find(b);
        if(x!=y){
            if(size[x]>size[y]){
                size[x]+=size[y];
                size[y]=0;
                //fc[x]=min(fc[x],fc[y]);
                if(fc[x]>fc[y]){
                    fc[x]=fc[y];
                    cnt[x]=cnt[y];
                }else if(fc[x]==fc[y]){
                    cnt[x]+=cnt[y];
                }
                cnt[y]=0;
                root[y]=x;
            }else{
                size[y]+=size[x];
                size[x]=0;
                //fc[y]=max(fc[x],fc[y]);
                if(fc[y]>fc[x]){
                    fc[y]=fc[x];
                    cnt[y]=cnt[x];
                }else if(fc[y]==fc[x]){
                    cnt[y]+=cnt[x];
                }
                cnt[x]=0;
                root[x]=y;
            }
        }
    }
    long long ans=1;
    for(int i=1; i<=n; i++){
        if(size[i]>1){
            ans = (ans*(size[i]*(size[i]+1)/2-size[i]+1))%M;
        }
    }
    cout<<ans<<"\n";
}