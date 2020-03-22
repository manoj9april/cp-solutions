#include<bits/stdc++.h>

using namespace std;

int const lmt = 3e5+5;

int lt[lmt],rt[lmt],idx[lmt];

bool comp(int i, int j){
    if(lt[i]==lt[j]) return rt[i]>rt[j];

    return lt[i]<lt[j];
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>lt[i]>>rt[i];
        idx[i]=i;
    }
    sort(idx,idx+n,comp);
    int ml = 0;
    bool ok=true;
    for(int i=0; i<n; i++){
        if(rt[idx[i]]<=ml){
            cout<<idx[i]+1<<" ";
            for(int j=0; j<i; j++){
                if(rt[idx[j]]==ml){
                    cout<<idx[j]+1<<"\n";
                    break;
                }
            }
            ok=false; break;
        }
        ml = max(ml,rt[idx[i]]);
    }
    if(ok){
        cout<<"-1 -1\n";
    }
}