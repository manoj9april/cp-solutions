#include<bits/stdc++.h>

using namespace std;

int const lmt = 2e5+6;

pair<char,int>  q[lmt];
int ans[lmt];
map<int,int> m;
vector< pair<int,int> > c;
int main(){
    int n; cin>>n;
    for(int i=1; i<=n; i++){
        cin>>q[i].first>>q[i].second;
        if(!m[q[i].second])ans[i]=-1;
        m[q[i].second] = 1;
    }
    m.clear();
    for(int i=1; i<=n; i++){
        
    }
}