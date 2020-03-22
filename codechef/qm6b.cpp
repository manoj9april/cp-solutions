#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int a[n];
        deque<int> q;
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int m = 0;
        for(int i=0; i<k; i++){
            while(!q.empty() && q.back()<a[i]){
                q.pop_back();
            }
            q.push_back(a[i]);

            m = max(m,a[i]);
        }

        for(int i=k; i<n; i++){
            if(q.front()==a[i-k]){
                q.pop_front();
            }
            while(!q.empty() && q.back()<a[i]){
                q.pop_back();
            }
            q.push_back(a[i]);
            m = min(m, q.front());
        }

        cout<<m<<"\n";
    }
}