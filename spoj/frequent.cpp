#include<bits/stdc++.h>

using namespace std;

struct nd{
    int s,e;
    int pre,suf,best;
    nd(){
        s=e=-1;
        pre=suf=best=0;
    }
};

int n,m;
int a[100005];
nd tree[400005];

nd merge(nd left, nd right){
    nd res;
    if(left.s==-1) res = right;
    else if(right.s==-1) res = left;
    else{
        res.s=left.s;
        res.e=right.e;
        res.pre = left.pre;
        res.suf = right.suf;
        if(a[left.s]==a[right.s]) res.pre += right.pre;
        if(a[left.e]==a[right.e]) res.suf += right.suf;
        res.best=max(max(left.best,right.best),max(res.pre,res.suf));
        if(a[left.e]==a[right.s])res.best = max(res.best, left.suf+right.pre);
    }
    return res;
}

void build(int node,int start, int end){
    if(start==end){
        tree[node].s=tree[node].e=start;
        tree[node].pre=1;
        tree[node].suf=1;
        tree[node].best=1;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=merge(tree[2*node],tree[2*node+1]);
    }
}


pair<int, nd> query(int node, int start, int end, int l, int r){
    if(l>end || r<start){
        nd test;
        test.s=-1;
        return make_pair(0,test);
    }
    else if(start>=l && end<=r){
        return make_pair(end-start+1,tree[node]);
    }else{
        int mid = (start+end)/2;
        pair<int, nd> a =  query(2*node,start,mid,l,r);
        pair<int, nd> b =  query(2*node +1,mid+1,end,l,r);
        if(a.second.s!=-1) a.second.s=mid-a.first +1;
        if(b.second.e!=-1) b.second.e=mid+b.first;
        return make_pair(a.first+b.first,merge(a.second,b.second));
    }
}

int main(){
    cin>>n;
    while(n){
        cin>>m;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        
        build(1,1,n);
        for(int i=1; i<=m; i++){
            int x,y;
            cin>>x>>y;
            cout<<query(1,1,n,x,y).second.best<<endl;
        }
        cin>>n;
    }
    
}