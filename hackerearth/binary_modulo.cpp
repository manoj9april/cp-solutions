#include<bits/stdc++.h>

using namespace std;

int n,m;
int b[4]={1,2,4,3};
int a[10005];
int tree[40005];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        int pw = (end - mid)%4;

        tree[node]=((tree[2*node]*(b[pw]))%5+tree[2*node+1])%5;
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
        
        int pw = (end - mid)%4;
        tree[node]=((tree[2*node]*(b[pw]))%5+tree[2*node+1])%5;
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(l<=start && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int left =  query(2*node,start,mid,l,r);
        int right =  query(2*node +1,mid+1,end,l,r);

        int pw = (r - mid)%4;
        if(end<r){
            pw = (end-mid)%4;
        }
        return ((left*b[pw])%5+right)%5;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        string str;
        cin>>str;
        int len = str.length();
        for(int i=1; i<=len; i++){
            a[i] = str[i-1]-'0';
        }
        build(1,1,len);
        cin>>m;
        for(int i=1; i<=m; i++){
            int type,x,y;
            cin>>type>>x>>y;
            if(type){
                update(1,1,len,x+1,y);
            }else{
                cout<<query(1,1,len,x+1,y+1)<<endl;
            }
        }
    }
}