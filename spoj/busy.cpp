#include<bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int const lmt = 1e5+5;
pii sc[lmt];

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            cin>>sc[i].second>>sc[i].first;
        }

        sort(sc,sc+n);
        int end=0;
        int cnt=0;
        for(int i=0; i<n; i++){
            if(sc[i].second>=end){
                cnt++;
                end =  sc[i].first;
            }
        }

        cout<<cnt<<"\n";
    }
}