#include<bits/stdc++.h>

using namespace std;

struct nod{
    int ls,rs,ms,ts;
};

int n,m;
int a[100005];
nod tree[400005];

void build(int node,int start, int end){
    if(start==end){
        tree[node].ls=tree[node].rs=tree[node].ms=tree[node].ts=a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        nod L =tree[2*node];
        nod R = tree[2*node+1];
        int a,b,c;
        a=tree[node].ls=max(L.ls, L.ts+R.ls);
        b=tree[node].rs=max(R.rs, L.rs+R.ts);
        c=tree[node].ts=L.ts + R.ts;
        tree[node].ms = max(a,max(b,max(L.rs+R.ls,max(L.ms,R.ms))));
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        tree[node].ls=tree[node].rs=tree[node].ms=tree[node].ts=a[start];
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        nod L =tree[2*node];
        nod R = tree[2*node+1];
        int a,b,c;
        a=tree[node].ls=max(L.ls, L.ts+R.ls);
        b=tree[node].rs=max(R.rs, L.rs+R.ts);
        c=tree[node].ts=L.ts + R.ts;
        tree[node].ms = max(a,max(b,max(L.rs+R.ls,max(L.ms,R.ms))));
    }
}

nod query(int node, int start, int end, int l, int r){
    if(l>end || r<start){
        nod res;
        res.ms=-200000;
        return res;
    }
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        nod L =  query(2*node,start,mid,l,r);
        nod R =  query(2*node +1,mid+1,end,l,r);
        if(L.ms==-200000)return R;
        else if(R.ms==-200000) return L;
        nod res;
        int a,b,c;
        a=res.ls=max(L.ls, L.ts+R.ls);
        b=res.rs=max(R.rs, L.rs+R.ts);
        c=res.ts=L.ts + R.ts;
        res.ms = max(a,max(b,max(L.rs+R.ls,max(L.ms,R.ms))));
        return res;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    cin>>m;
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        cout<<query(1,1,n,x,y).ms<<endl;
    }
}