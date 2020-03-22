#include<bits/stdc++.h>

using namespace std;

const int lmt=1e5 + 4;
int a[lmt];
int tree[4*lmt+1];
int lazy[4*lmt+1];

int merge(int l, int r){
    return l+r;
}

void build(int node, int s, int e){
    if(s==e){
        tree[node]=a[s];
        lazy[node]=0;
        return;
    }

    int mid = (s+e)>>1;
    int ln=node<<1;
    int rn = ln|1;
    build(ln, s, mid);
    build(rn, mid+1, e);

    tree[node] = merge(tree[ln],tree[rn]);
    lazy[node]=0;
}

void update(int node, int s, int e, int qs, int qe, int val){
    int ln=node<<1;
    int rn = ln|1;

    if(lazy[node]){
        tree[node] -= (e-s+1)*lazy[node];
        if(tree[node]<0) tree[node]=0;
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
    }

    if(s>e || e<qs || qe<s){
        return;
    }

    if(qs<=s && e<=qe){
        tree[node] -= (e-s+1)*val;
        if(tree[node]<0) tree[node]=0;
        if(s!=e){
            lazy[ln] += val;
            lazy[rn] += val;
        }
        return;
    }

    int mid = (s+e)>>1;

    update(ln, s, mid,qs,qe,val);
    update(rn, mid+1, e, qs, qe, val);

    tree[node] = merge(tree[ln],tree[rn]);
}

int query(int node, int s, int e, int qs, int qe){
    int ln=node<<1;
    int rn = ln|1;

    if(lazy[node]){
        tree[node] -= (e-s+1)*lazy[node];
        if(tree[node]<0) tree[node]=0;
        if(s!=e){
            lazy[ln] += lazy[node];
            lazy[rn] += lazy[node];
        }
        lazy[node]=0;
    }

    if(s>e || e<qs || qe<s){
        return 0;
    }

    if(qs<=s && e<=qe){
        return tree[node];
    }

    int mid = (s+e)>>1;

    int left = query(ln, s, mid,qs,qe);
    int right = query(rn, mid+1, e, qs, qe);

    return merge(left,right);
}


int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    
    int t;
    int prev,cur;
    for(int i=1; i<=n; i++){
        cin>>t;
        update(1,1,n,i,i,-a[i]);
        prev = query(1,1,n,1,i);
        update(1,1,n,1,i,t);
        cur = query(1,1,n,1,i);
        cout<<prev-cur<<" ";
    }
    cout<<"\n";
}