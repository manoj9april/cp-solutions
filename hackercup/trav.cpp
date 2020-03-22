#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2001;
int let[lmt],rit[lmt];
vector<int> preo,posto;
void pre(int i){
    if(!i)return;
    preo.push_back(i);
    //cout<<i<<" ";
    pre(let[i]);
    pre(rit[i]);
}
void post(int i){
    if(!i) return;
    post(let[i]);
    post(rit[i]);
    posto.push_back(i);
}
int root[lmt],size[lmt];
int label[lmt];
int find(int i){
    if(root[i]!=i){
        return root[i]=find(root[i]);
    }
    return root[i];
}
int main(){
    freopen("trav.in","r",stdin);
    freopen("trav.out","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        int n,k;
        cin>>n>>k;
        for(int i=1; i<=n; i++){
            cin>>let[i]>>rit[i];
        }
        preo.clear();
        posto.clear();
        preo.push_back(0);
        posto.push_back(0);
        pre(1);
        post(1);
        
        for(int i=1; i<=n; i++){
            root[i]=i;
            size[i]=1;
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            int a=preo[i],b=posto[i];
            int x = find(a);
            int y = find(b);
            if(x!=y){
                root[y]=x;
                size[x]+= size[y];
                size[y]=0;
            }
        }
        for(int i=1; i<=n; i++){
            if(size[i]){
                cnt++;
                label[i]=cnt;
            }
        }
        for(int i=1; i<=n; i++){
            if(size[i]){
                ;
            }else{
                label[i]=label[find(i)];
            }
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        //cout<<cnt<<" ";
        if(cnt<k){
            cout<<"Impossible";
        }else{
            for(int i=1; i<=n; i++){
                if(label[i]>k)label[i]=k;
                cout<<label[i]<<" ";
            }
        }
        //
        cout<<"\n";
    }
}
