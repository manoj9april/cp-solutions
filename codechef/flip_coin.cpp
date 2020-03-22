#include<bits/stdc++.h>

using namespace std;

const int lmt=1e5+4;
int a[lmt];
int tree[4*lmt+1];
int lazy[4*lmt+1];

int merge(int l, int r){
    return l+r;
}


void update(int node, int s, int e, int qs, int qe, int val){
    int ln=node<<1;
    int rn = ln|1;


    if(s>e || e<qs || qe<s){
        return;
    }

    if(lazy[node]){
        tree[node] = (e-s+1)-tree[node];
        if(s!=e){
            lazy[ln] += lazy[node];lazy[ln] %=2;
            lazy[rn] += lazy[node];lazy[rn] %=2;
        }
        lazy[node]=0;
    }

    if(qs<=s && e<=qe){
        lazy[node]=val;
        tree[node] = (e-s+1)-tree[node];
        if(s!=e){
            lazy[ln] += lazy[node];lazy[ln] %=2;
            lazy[rn] += lazy[node];lazy[rn] %=2;
        }
        lazy[node]=0;
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

    if(s>e || e<qs || qe<s){
        return 0;
    }

    if(lazy[node]){
        tree[node] = (e-s+1)-tree[node];
        if(s!=e){
            lazy[ln] += lazy[node];lazy[ln] %= 2;
            lazy[rn] += lazy[node];lazy[rn] %= 2;
        }
        lazy[node]=0;
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
    int n,m;
    cin>>n>>m;
    int ty,qs,qe;
    while(m--){
        cin>>ty>>qs>>qe;
        qs++; qe++;
        if(ty==0){
            update(1,1,n,qs,qe,1);
        }else{
            cout<<query(1,1,n,qs,qe)<<"\n";
        }
    }
}

