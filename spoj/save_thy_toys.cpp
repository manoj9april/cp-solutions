#include<bits/stdc++.h>

using namespace std;

int n;
int a[100002];

int solve(int picked, int pick){
    int sum =0;
    if(picked==n) return sum;
    else{
        for(int i=1; i<=pick && i<=n; i++){
            sum += a[picked+pick];
        }
        return sum+max(solve(picked+2*pick,1),max(solve(picked+2*pick,2),solve(picked+2*pick,3)));
    }
}

int main(){
    int t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1; i<=n; i++) cin>>a[i];

        int ans = max(solve(0,1),max(solve(0,2),solve(0,3)));
        cout<<ans<<endl;
    }
}