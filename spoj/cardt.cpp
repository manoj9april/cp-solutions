#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pii;

int const lmt = 1e5+1;

int arr[lmt];
int tree[4*lmt];

void build(int node, int s,int e){
    if(s==e){
        arr[s]=1;
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
        arr[s]=0;
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
    if(e<qs || qe<s || qs>qe) return 0;

    if(qs<=s && e<=qe) return tree[node];

    int mid = s + (e-s)/2;
    int lt = query(2*node+1,s,mid,qs,qe);
    int rt = query(2*node+2,mid+1,e,qs,qe);
    return lt+rt;
}

int n; 
int bs(int tar,int lo,int hi){
    int mid;
    int st=lo;
    while(lo<=hi){
        mid = lo + (hi-lo)/2;
        if(query(0,0,n-1,st,mid)<=tar) lo=mid+1;
        else hi = mid-1;
    }

    return (lo)%n;
}


int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        build(0,0,n-1);
        int ans[n];
        
        for(int i=0; i<n; i++){
            ans[i]=0;
        }

        int prev=1;
        /*
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
        */
        update(0,0,n-1,prev);
        ans[1]=1;
        for(int i=2; i<=n-1; i++){
            int ts = query(0,0,n-1,0,n-1);
            if(query(0,0,n-1,(prev+1)%n,n-1)>i){
                prev = bs(i,(prev+1)%n,n-1);
                ans[prev]=i;
                update(0,0,n-1,prev);
            }else if(ts>i){
                int tt = query(0,0,n-1,(prev+1)%n,n-1);
                prev = bs(i-tt,0,prev);
                ans[prev]=i;
                update(0,0,n-1,prev);
            }else{
                int tar = i%ts;
                prev = bs(tar,(prev+1)%n,n-1);
                ans[prev]=i;
                update(0,0,n-1,prev);
            }
            /*
            for(int i=0; i<n; i++){
                cout<<arr[i]<<" ";
            }cout<<endl;
            */
        }//cout<<"\n";

        for(int i=0; i<n; i++){
            cout<<ans[i]<<" ";
        }cout<<"\n";
    }
}