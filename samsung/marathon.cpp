#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

struct d{
    ll m,s,e,t;
} p[5];

ll const mx = 1e17+2;
int const lmt=601;
ll a[lmt][5],b[lmt][5];
ll E,D;
ll dp[lmt][lmt];

void solve(ll e, ll d){
    ll &ans = dp[e][d];
    ans=mx;
    if(d==0){
        ans=0;
    }
    else if(e==0){
        ans = mx;
    }
    for(int i=0; i<5; i++){
        if(e-p[i].e>=0) ans = min(ans, p[i].t + dp[e-p[i].e][d-1]);
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
    
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        cin>>E>>D;
        
        for(int i=0; i<5; i++){
            cin>>p[i].m>>p[i].s>>p[i].e;
            p[i].t = 60*p[i].m + p[i].s; 
            // cout<<"jdkj\n";
        }

        for(int e=0; e<=E; e++){
            for(int d=0; d<=D; d++){
                solve(e,d);
            }
        }
        cout<<dp[E][D]<<"\n";
    }

}
