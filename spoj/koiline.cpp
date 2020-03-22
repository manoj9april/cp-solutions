#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pii;

int const lmt = 1e5+1;

int tree[4*lmt];

void build(int node, int s,int e){
    if(s==e){
        tree[node]=1;
        return;
    }
    int mid = s + (e-s)/2;
    build(2*node+1,s,mid);
    build(2*node+2,mid+1,e);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

void update(int node,int s,int e, int idx){
    if(s==e){
        tree[node]=0;
        return;
    }
    int mid = s + (e-s)/2;
    if(s<=idx && idx<=mid)
        update(2*node+1,s,mid,idx);
    else
        update(2*node+2,mid+1,e,idx);

    tree[node] = tree[2*node+1] + tree[2*node+2];
}

int query(int node,int s,int e, int qs, int qe){
    if(e<qs || qe<s) return 0;

    if(qs<=s && e<=qe) return tree[node];

    int mid = s + (e-s)/2;
    int lt = query(2*node+1,s,mid,qs,qe);
    int rt = query(2*node+2,mid+1,e,qs,qe);
    return lt+rt;
}
int main(){
    int n; cin>>n;
    int h[n];
    for(int i=0; i<n; i++){
        cin>>h[i];
    }

    sort(h,h+n);

    int sq[n];
    for(int i=0; i<n; i++)cin>>sq[i];

    int real[n];
    int lo,hi,mid;
    build(0,0,n-1);
    for(int i=n-1; i>=0; i--){
        lo=0; hi=n-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            if(query(0,0,n-1,0,mid)<=sq[i]) lo=mid+1;
            else hi = mid-1;
        }
        real[i] = h[lo];
        update(0,0,n-1,lo);
    }

    for(int i=0; i<n; i++){
        cout<<real[i]<<"\n";
    }
}


/*
134  
167
120
119
156
120
167
182
155
163
172
145

120
155
120
119
163
120
182
182
155
163
172
145

*/