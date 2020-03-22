#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;

    int clas[n];
    memset(clas, 0, sizeof clas);
    pii mem[n*m];

    int ptr=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin>>mem[ptr].first;
            mem[ptr].second = i;
            ptr++;
        }
    }
    if(n==1 && m==1){
        cout<<0<<"\n";
        return 0;
    }
    sort(mem, mem + n*m);

    int lt=0,rt=1;
    clas[mem[0].second]++;
    int cnt=1;
    int diff = 1e9+8;
    while(lt<rt && rt<n*m){
        if(cnt<n){
            if(clas[mem[rt].second]==0) cnt++;
            clas[mem[rt].second]++;
            rt++;
        }else if(lt<rt){
            diff = min(diff,mem[rt-1].first-mem[lt].first);
            if(clas[mem[lt].second]==1) cnt--;
            clas[mem[lt].second]--;
            lt++;
        }
    }

    cout<<diff<<"\n";
}