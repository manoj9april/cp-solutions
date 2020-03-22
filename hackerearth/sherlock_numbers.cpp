#include <bits/stdc++.h>

using namespace std;


int n,k,p;
int karr[100005];

int lb(int lo, int target){
    int mid,hi=k;
    while(lo<hi){
        mid  = lo + (hi-lo+1)/2;
        if(karr[mid]<=target) lo = mid;
        else hi = mid-1;
    }
    return lo;
}

int main(){
    int t; cin>>t;
    while(t--){
        
        cin>>n>>k>>p;
        
        karr[0]=0;
        for(int i=1; i<=k; i++){
            cin>>karr[i];
        }
        if(p>n-k){
            cout<<"-1\n";
            continue;
        }
        int nlo,olo=0;
        while(true){
            
            nlo = lb(olo,p);

            if(nlo-olo==0){
                break;
            }
            p += (nlo-olo);
            olo = nlo;
        }

        cout<<p<<endl;
    }
}