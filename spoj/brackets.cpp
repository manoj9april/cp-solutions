#include<bits/stdc++.h>

using namespace std;

struct nod{
    long long open,close;
};

int n,m;
string a;
nod tree[400005];

void merge(nod &res,nod l, nod r){
    long long a = l.open;
    long long b = r.close;
    a -= min(l.open,r.close);
    b -= min(l.open,r.close);

    res.open = r.open+a;
    res.close = l.close+b;
}

void build(int node,int start, int end){
    if(start==end){
        tree[node].open=(a[start]=='('?1:0);
        tree[node].close=(a[start]==')'?1:0);
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        merge(tree[node] ,tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx){
    if(start==end){
        int tmp = tree[node].open;
        tree[node].open = tree[node].close;
        tree[node].close = tmp;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx);
        }else{
            update(2*node +1,mid+1,end,idx);
        }
        
        merge(tree[node] ,tree[2*node],tree[2*node+1]);
    }
}
/*
nod query(int node, int start, int end, int l, int r){
    if(l>end || r<start){
        nod res;
        res.close = res.open = 0;
    }
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        nod a =  query(2*node,start,mid,l,r);
        nod b =  query(2*node +1,mid+1,end,l,r);
        nod res;
        merge(res,a,b);
        return res;
    }
}
*/

int main(){
    ios_base::sync_with_stdio(0);
    int t=10;
    int p=1;
    while(t--){
        cout<<"Test "<<p<<":\n"; p++;
        int n; cin>>n;
        cin>>a;
        build(1,0,n-1);
        /*
        for(int i=1; i<8; i++){
            cout<<tree[i].open<<" "<<tree[i].close<<"\n";
        }*/
        int m; cin>>m;
        for(int j=1; j<=m; j++){
            int q; cin>>q;
            if(q==0){
                if(tree[1].open==0 && tree[1].close==0){
                    cout<<"YES\n";
                }else{
                    cout<<"NO\n";
                }
                //cout<<tree[1].open<<" "<<tree[1].close<<"\n";
            }else{
                update(1,0,n-1,q-1);
                //cout<<tree[1].open<<" "<<tree[1].close<<"\n";
            }
        }
    }
}