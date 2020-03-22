#include<bits/stdc++.h>

using namespace std;

int a[50005];
int n,k;

bool check(int choc){
    int st=0;
    bool got=false;
    for(int i=0; i<n; i++){
        st += a[i]/choc;
        if(st>=k) {got=true; break;}
    }

    return got;
}


int lb(int lo, int hi){
    int mid;
    while(lo<hi){
        mid = lo + (hi-lo+1)/2;
        if(check(mid)) lo =mid;
        else hi = mid-1;
    }

    return lo;
}

int main(){
    int t; cin>>t;
    while(t--){
        
        cin>>n>>k;
        
        int hi=0;
        for(int i=0; i<n; i++){
            cin>>a[i];    
            hi = max(hi, a[i]);
        }
        int ans=0;
        ans = lb(0,hi);
        
        cout<<ans<<endl;
    }
}