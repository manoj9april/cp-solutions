#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n,b;
    cin>>n>>b;
    int a[n+1],pre[n+1];
    pre[0]=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        pre[i] = (a[i]%2==0?1:-1);
    }
    vector<int> sol;
    for(int i=1; i<n; i++){
        pre[i] += pre[i-1];
        if(pre[i]==0){
            sol.push_back(abs(a[i+1]-a[i]));
        }
    }
    ll sm = 0,cnt=0;
    sort(sol.begin(),sol.end());
    for(int i=0; i<sol.size(); i++){
        sm += 1LL*sol[i];
        if(sm>b)break;
        cnt++;
    }

    cout<<cnt<<"\n";
}