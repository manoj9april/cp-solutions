#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+1;
int n,m;
int a[lmt];
int tree[4*lmt];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=a[start]=1;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx){
    if(start==end){
        a[idx]=0;
        tree[node]=0;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx);
        }else{
            update(2*node +1,mid+1,end,idx);
        }
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start || r<l) return 0;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int arr[n+1];
        for(int i=1; i<=n; i++){
            cin>>arr[i];
        }
        build(1,1,n);
        int ans[n+1];
        for(int i=n; i>0; i--){
            int tar = arr[i];
            int lo=1,mid,hi=n;
            int ts = query(1,1,n,1,n);
            tar = ts-tar;
            while(lo<=hi){
                mid = (lo+hi)/2;
                if(query(1,1,n,1,mid)<tar)  lo=mid+1;
                else hi = mid-1;
            }
            ans[i]=lo;
            update(1,1,n,lo);
        }

        for(int i=1; i<=n; i++){
            cout<<ans[i]<<" ";
        }cout<<"\n";
    }
}