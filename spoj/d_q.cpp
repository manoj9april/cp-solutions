#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+3;
int check[lmt];

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
    memset(check, false, sizeof check);
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
        q[i].L--; q[i].R--;
        q[i].idx=i;
    }

    sort(q,q+m, comp);

    int pl=0,pr=-1,ps=0;
    for(int i=0; i<m; i++){
        int l = q[i].L; 
        int r = q[i].R;

        if(pl<l){
            while(pl<l){
                check[arr[pl]]--;
                if(check[arr[pl]]==0) ps--;
                pl++;
            }
        }else if(pl>l){
            while(pl>l){
                if(check[arr[pl-1]]==0) ps++;
                check[arr[pl-1]]++;
                pl--; 
            }
        }
        //cout<<ps<<endl;

        if(pr>r){
            while(pr>r){
                check[arr[pr]]--;
                if(check[arr[pr]]==0) ps--;
                pr--;
            }
        }else if(pr<r){
            while(pr<r){
                if(check[arr[pr+1]]==0) ps++;
                check[arr[pr+1]]++;
                pr++; 
            }
        }
        //cout<<l<<" "<<r<<" "<<ps<<endl;
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