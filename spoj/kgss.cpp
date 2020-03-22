#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[100005];
int tree[400005];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=start;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        int i = tree[2*node];
        int j = tree[2*node+1];
        tree[node] = a[i]>a[j] ? i:j ;
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        //tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        int i = tree[2*node];
        int j = tree[2*node+1];
        tree[node] = a[i]>a[j] ? i:j ;
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return -1;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int i =  query(2*node,start,mid,l,r);
        int j =  query(2*node +1,mid+1,end,l,r);
        if(i==-1) return j;
        else if(j==-1) return i;
        else{
            return (a[i]>a[j] ? i:j );
        }
    }
}

int main(){
    int t=1; //cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++){
            cin>>a[i];
        }
        build(1,1,n);
        cin>>m;
        for(int i=1; i<=m; i++){
            char q;int x,y;
            cin>>q>>x>>y;
            if(q=='U'){
                update(1,1,n,x,y);
            }else{
                int d = query(1,1,n,x,y);
                int max1 = a[d];
                update(1,1,n,d,0);
                int f = query(1,1,n,x,y);
                int max2 = a[f];
                update(1,1,n,d,max1);
                cout<<max1+max2<<endl;
            }
        }
    }
}