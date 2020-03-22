#include <bits/stdc++.h>

using namespace std;

#define pb   push_back

vector<int >  v[100005];

int lb(int hi, int b, int target){
    int mid;
    int lo=0;
    while(lo<hi){
        mid = lo + (hi-lo+1)/2;

        if(v[b][mid]<= target) lo = mid;
        else hi = mid-1;
    }

    return lo;
}

int main(){
    int n,q;
    int a[2*n];
    for(int i=0; i<n; i++){
        cin>>a[i];
        a[i+n]=a[i];
    }
    for(int i=0; i<2*n; i++){
        v[a[i]].pb(i);
    }

    int x,y;
    while(q--){
        cin>>x>>y;

        int idx2;
        int mind=1000000;
        for(int idx : v[x]){
            idx2 = lb(v[y].size()-1, y, idx);
            mind = min(mind, abs(idx - v[y][idx2]));
            mind = min(mind, abs(idx - v[y][idx2+1]));
        }
        cout<<mind/2<<endl;
    }
}