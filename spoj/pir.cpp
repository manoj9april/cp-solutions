#include<bits/stdc++.h>

using namespace std;

#define ll long long
int const lmt = 1e5+1;
int n,m;
int dis[lmt],sz[lmt];
int tree[4*lmt],t2[4*lmt];
ll B;
map<int,int> mp;
struct ck {
    ll ss,dd,idx;
};
ck ppt[lmt];
bool cmp(ck a, ck b){
    return a.ss<b.ss;
}

void build(int node,int start, int end){
    if(start==end){
        int idx= mp[start];
        tree[node]=dis[idx];
        t2[node]=1;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        //a[idx]=val;
        tree[node]=0;
        t2[node]=0;
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

int query(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}

int q2(int node, int start, int end, int l, int r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return t2[node];
    }else{
        int mid = (start+end)/2;
        int a =  query(2*node,start,mid,l,r);
        int b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}



bool check(ll mid){
    ll sum,cnt,ans=0; 
    build(1,1,n); 
    for(int i=1; i<=n; i++){
        int idx = mp[i];

        update(1,1,n,idx,0);
        cnt = q2(1,1,n,1,idx);
        sum = query(1,1,n,1,idx);

        ans += (cnt*dis[idx]-sum);
    }

    return ans<B;
}
int main(){
    cin>>n>>B;

    for(int i=1; i<=n; i++){
        cin>>sz[i];
    }
    for(int i=1; i<=n; i++){
        cin>>dis[i];

        ppt[i].ss=sz[i];
        ppt[i].dd=dis[i];
        ppt[i].idx=i;
    }
    sort(ppt+1,ppt+n+1,cmp);
    for(int i=1; i<=n; i++){
        mp[ppt[i].idx]=i;
    }
    ll mid,lo=0,hi=1e18+1;
    while(lo<=hi){
        mid = lo+(hi-lo)/2;
        if(check(mid)) hi=mid-1;
        else lo = mid+1;
    }

    cout<<lo<<"\n";
}