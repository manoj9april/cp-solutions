#include<bits/stdc++.h>

using namespace std;

int const lmt=1e5+4;
pair<int,int> pw[lmt];
int coins[lmt];
long long ans[lmt];

int main(){
    int n,k;
    cin>>n>>k;
    int pr;
    for(int i=0; i<n; i++){
        cin>>pr;
        pw[i].first=pr;
        pw[i].second=i;
    }
    sort(pw,pw+n);
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    long long sum=0;
    priority_queue<int,vector<int>, greater<int> > q;
    for(int i=0; i<n; i++){
        int pos = pw[i].second;
        if(i<k){
            sum += coins[pos];
            q.push(coins[pos]);
            ans[pos]=sum;
        }else{
            sum+=coins[pos];
            ans[pos]=sum;
            q.push(coins[pos]);
            sum -= q.top();
            q.pop();
        }
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}