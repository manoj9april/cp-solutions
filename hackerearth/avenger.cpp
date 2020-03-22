#include<bits/stdc++.h>

using namespace std;

int n,t;
int a[32005];
int tree[4*32000 +5];

bool prime[1000005];

void fprime(){
    
    int j;
    memset(a,true,sizeof(a));
    for(int i=2; i<1000005; i++){
        if(a[i]){
            //prime.pb(i);
            j=2*i;
            while(j<1000005){
                a[j] = false;
                j += i;
            }
        }
    }
}

void build(int node,int start, int end){
    if(start==end){
        tree[node]=prime[a[start]]?1:0;
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        
        tree[node]=(tree[2*node]+tree[2*node+1]);
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start==end){
        a[idx]=val;
        tree[node]=prime[val]?1:0;
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

int main(){
	fprime();
	int tc; cin>>tc;
	while(tc--){
	    cin>>n;
	    for(int i=1; i<=n; i++){
	        cin>>a[i];
	    }
	    
	    build(1,1,n);
	    cin>>t;
	    for(int i=1; i<=t; i++){
	        char q;int a,b;
	        cin>>q>>a>>b;
	        if(q=='C'){
	            update(1,1,n,a,b);
	        }else{
	            cout<<query(1,1,n,a,b)<<endl;
	        }
	    }
	}
}