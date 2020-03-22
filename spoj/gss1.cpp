#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[50005];
int tree[200005][3];

void build(int node,int start, int end){
    if(start==end){
        tree[node][0]=a[start];
        tree[node][1] = start;
        tree[node][2] = end;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        int* g = tree[2*node];
        int* h = tree[2*node+1];
        int maxa = INT_MIN;
        if(g[2]==mid && h[1]==mid+1 && g[0]+h[0]>maxa){
            maxa=tree[node][0] = g[0]+h[0];   
            tree[node][1] = g[1];
            tree[node][2] = h[2];
        }else{
        	if(g[0]>maxa){
        		maxa=tree[node][0] = g[0];   
	            tree[node][1] = g[1];
	            tree[node][2] = g[2];	
        	}if(h[0]>maxa){
        		maxa=tree[node][0] = h[0];   
	            tree[node][1] = h[1];
	            tree[node][2] = h[2];
        	}
            //tree[node] = g[0]>h[0] ? g:h;
        }
    }
}
/*
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
        
        tree[node]=min(tree[2*node],tree[2*node+1]);
    }
}
*/

int* query(int node, int start, int end, int l, int r){
    if(l>end || r<start){
        int* h= new int[3];
        h[0] = -1000000000;
        h[1] = h[2] =-1;
        return h;
    }
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int* g =  query(2*node,start,mid,l,r);
        int* h =  query(2*node +1,mid+1,end,l,r);
        int* f = new int[3];f[0]=INT_MIN;
        if( g[1]!=-1 && h[1]!=-1 && g[2]==mid && h[1]==mid+1 && g[0]+h[0]>f[0]){
            
            f[0] = g[0]+h[0];   
            f[1] = g[1];
            f[2] = h[2];
        }
        if(g[1]!=-1 && g[0]>f[0]){
        	f[0] = g[0];   
            f[1] = g[1];
            f[2] = g[2];
        }
        if(h[1]!=-1 && h[0]>f[0]){
        	f[0] = h[0];   
            f[1] = h[1];
            f[2] = h[2];
        }
        return f;
    }
}

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    cin>>m;
    build(1,1,n);
    for(int i=1; i<=m; i++){
        int x,y;
        cin>>x>>y;
        int* ans = new int[3];
        ans = query(1,1,n,x,y);
        cout<<ans[0]<<endl;
    }
}