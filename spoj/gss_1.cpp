#include<bits/stdc++.h>

using namespace std;

struct nod{
    long long ls,rs,ms,ts;
};

int n,m;
long long a[100005];
nod tree[400020];

void build(int node,int start, int end){
    if(start==end){
        tree[node].ls=tree[node].rs=tree[node].ms=tree[node].ts=a[start];
    }else{
        int mid = (start+end)/2;
        build(2*node,start,mid);
        build(2*node +1, mid+1, end);
        nod L =tree[2*node];
        nod R = tree[2*node+1];
        long long a,b,c;
        a=tree[node].ls=max(L.ls, L.ts+R.ls);
        b=tree[node].rs=max(R.rs, L.rs+R.ts);
        c=tree[node].ts=L.ts + R.ts;
        tree[node].ms = max(a,max(b,max(L.rs+R.ls,max(L.ms,R.ms))));
    }
}

nod query(int node, int start, int end, int l, int r){
    if(l>end || r<start){
        nod res;
        res.ms=-(1LL*1e9);
        return res;
    }
    else if(start>=l && end<=r){
        return tree[node];
    }else{
        int mid = (start+end)/2;
        nod L =  query(2*node,start,mid,l,r);
        nod R =  query(2*node +1,mid+1,end,l,r);
        if(L.ms==-(1LL*(1e9)))return R;
        else if(R.ms==-(1LL*(1e9))) return L;
        nod res;
        long long a,b,c;
        a=res.ls=max(L.ls, L.ts+R.ls);
        b=res.rs=max(R.rs, L.rs+R.ts);
        c=res.ts=L.ts + R.ts;
        res.ms = max(a,max(b,max(L.rs+R.ls,max(L.ms,R.ms))));
        return res;
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--){
        cin>>n;
        long long pre[n+1];
        pre[0]=0;
        for(int i=1; i<=n; i++){
            cin>>a[i];
            pre[i] = pre[i-1]+a[i];
        }
        
        build(1,1,n);
        cin>>m;
        for(int i=1; i<=m; i++){
            int x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            long long ans;
            if(y1>x2){
                nod L = query(1,1,n,x1,x2-1);
                nod R = query(1,1,n,x2,y2);
                long long op1 = L.rs + R.ls;
                
                L = query(1,1,n,x1,y1);
                R = query(1,1,n,y1+1,y2);
                long long op2 = L.rs + R.ls;

                ans = query(1,1,n,x2,y1).ms;
                ans = max(ans,max(op1,op2));
            }else{
                nod L = query(1,1,n,x1,y1);
                nod R = query(1,1,n,x2,y2);
                ans = (pre[x2-1]-pre[y1]) + L.rs+R.ls;
            }
            
            //cout<<L.rs<<" "<<R.ls<<" "<<(pre[x2-1]-pre[y1])<<"\n";
            cout<<ans<<"\n";
        }
    }
}