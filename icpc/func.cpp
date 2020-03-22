#include<bits/stdc++.h>

using namespace std;

#define ll long long

// be //////////////////////////////

ll mod;
ll be(ll a, ll n){
    ll ans=1;
    while(n){
        if(n&1) ans = (ans*a)%mod;

        n = (n>>1);
        a = (a*a)%mod;
    }
}

///////// direction  //////////////

int dx[8]={0,-1,-1,-1,0,1,1,1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

int dirx[]={};
int diry[]={};

///////// seg tree ///////////

int const lmt = 1e5+7;
ll tree[4*lmt+1];
ll a[lmt];

void build(int node,int start, int end){
    if(start==end){
        tree[node]=a[start];
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
        tree[node]=val;
    }
    else{
        int mid = (start+end)/2;
        if(idx>=start  && idx<=mid){
            update(2*node,start,mid,idx,val);
        }else{
            update(2*node +1,mid+1,end,idx,val);
        }
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

ll query(ll node, ll start, ll end, ll l, ll r){
    if(l>end || r<start) return 0;
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        ll mid = (start+end)/2;
        ll a =  query(2*node,start,mid,l,r);
        ll b =  query(2*node +1,mid+1,end,l,r);
        return (a+b);
    }
}

//////////////  lazy ////////////////////

