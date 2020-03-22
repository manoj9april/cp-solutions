#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define pii pair<int, int>

int const lmt = 1e7+3;
int d[lmt];
vector<pii> v;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int e;
    ll ans=0;
    for(int i=1; i<=n; i++){
        cin>>e;
        d[e]++;
        if(d[e]>k)ans=-1;
    }
    for(int i=1; i<=m; i++){
        cin>>e;
        v.push_back(make_pair(e,i));
    }
    if(ans==-1){
        cout<<ans<<"\n";
        return 0;
    }
    sort(v.begin(),v.end());

    vector<int> sol;
    ll today = d[0];
    int idx=0;
    for(int i=0; i<=1e7; i++){
        while(idx<m && today<k){
            
            sol.push_back(v[idx].second);
            idx++;today++;ans++;
        }

        while(idx<m && v[idx].first==i)idx++;
        today = d[i+1];
    }
    
    cout<<ans<<"\n";
    for(int i=0; i<ans; i++){
        cout<<sol[i]<<" ";
    }
    cout<<"\n";
}