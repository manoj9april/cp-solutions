#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+1;
int n,m,alice;
int a[lmt];
int tree[4*lmt];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=start;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        if(a[tree[2*node]]<a[tree[2*node+1]]){
            tree[node]=tree[2*node+1];
        }else{
            tree[node]=tree[2*node];
        }
    }
}

void update(int node, int start, int end, int idx){
    if(start==end){
        
        a[idx]++;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx);
        }else{
            update(2*node +1,mid+1,end,idx);
        }
        
        if(a[tree[2*node]]<a[tree[2*node+1]]){
            tree[node]=tree[2*node+1];
        }else{
            tree[node]=tree[2*node];
        }
    }
}

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start || r<l) return -1;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int i =  query(2*node,start,mid,l,r);
        int j =  query(2*node +1,mid+1,end,l,r);
        if(i==-1) return j;
        else if (j==-1) return i;
        if(a[i]<a[j]){
            return tree[j];
        }else{
            return tree[i];
        }
    }
}

int main(){
    cin>>n>>alice;
    int mx;
    bool nosol =false;
    build(1,1,lmt);
    int idx;
    int acnt=0;
    for(int i=1; i<=n; i++){
        cin>>idx;
        if(nosol) continue;
        if(idx!=alice)
            update(1,1,lmt,idx);
        else acnt++;

        mx = query(1,1,lmt,1,lmt);
        if(a[mx]<acnt){
            nosol = true;
            //cout<<i<<" "<<mx<<"===\n";
        }
    }
    if(nosol){
        cout<<"first-1\n";
    }else{

        cout<<mx<<"\n";
    }
    
}

/*

else if(a[i]==a[j]){
            if(tree[i]==alice) return tree[j];
            if(tree[j]==alice) return tree[i];
            return tree[i];
        }

        */