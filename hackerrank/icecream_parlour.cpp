#include<bits/stdc++.h>

using namespace std;

#define pb  push_back
#define mp  make_pair
#define f  first
#define s  second

int main(){
    int t; cin>>t;
    while(t--){
        int m,n;
        cin>>m>>n;
        pair<int ,int>  ic[n];

        int cost;
        for(int i=0; i<n; i++){
            cin>>cost;
            ic[i] = mp(cost,i+1);
        }
        sort(ic,ic+n);
        bool  found = false;
        int id1=-1,id2=-1;
        int start=0, end = n-1;
        while(start<end){
            if(ic[start].f + ic[end].f == m){
                found = true;
                id1=ic[start].s;
                id2=ic[end].s;
                break;
            }else if(ic[start].f + ic[end].f < m){
                start++;
            }else{
                end--;
            }
        }

        int small = min(id1,id2);
        int big = max(id1,id2);
        
        cout<<small<<" "<<big<<"\n";
    }
}