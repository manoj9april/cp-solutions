#include<bits/stdc++.h>

using namespace std;

int const lmt = 2e5+3;

struct query{
    int L,R,idx;
};

int block;

bool comp(query f, query s){
    if(f.L/block == s.L/block){
        return f.R<s.R;
    }

    return f.L/block < s.L/block;
}

int ans[lmt];

int main(){
    int n; cin>>n;
    block = int(sqrt(n));
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int m; cin>>m;
    query q[m];
    for(int i=0; i<m; i++){
        cin>>q[i].L>>q[i].R;
        q[i].idx=i;
    }

    sort(q,q+m, comp);

    int pl=0,pr=-1,ps=0;
    for(int i=0; i<m; i++){
        int l = q[i].L; 
        int r = q[i].R;

        if(pl<l){
            while(pl<l){
                ps -= arr[pl];
                pl++;
            }
        }else if(pl>l){
            while(pl>l){
                ps += arr[pl-1];
                pl--; 
            }
        }
        //cout<<ps<<endl;

        if(pr>r){
            while(pr>r){
                ps -= arr[pr];
                pr--;
            }
        }else if(pr<r){
            while(pr<r){
                ps += arr[pr+1];
                pr++;
            }
        }
        cout<<l<<" "<<r<<" "<<ps<<endl;
        ans[q[i].idx]=ps;
    }

    for(int i=0; i<m; i++){
        cout<<ans[i]<<"\n";
    }
}

/*
9
1 1 2 1 3 4 5 2 8
3
0 4
1 3
2 4
*/