#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+1;


struct d{
    int ans, open, close;
}tree[4*lmt];


d merge(d a, a b){
    d c;

    return c;
}

void build(int node,int start, int end){
    if(start==end){
        tree[node]=a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return INT_MAX;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        auto a =  query(2*node,start,mid,l,r);
        auto b =  query(2*node +1,mid+1,end,l,r);
        return merge(a,b);
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1; i<=m; i++){
        char q;int x,y;
        cin>>q>>x>>y;
        if(q=='u'){
            update(1,1,n,x,y);
        }else{
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
}