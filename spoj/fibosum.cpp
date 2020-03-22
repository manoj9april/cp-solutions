#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;


void mul_matrix(ll a[3][3],ll b[3][3]){
    ll c[3][3];
    memset(c,0,sizeof c);
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                c[i][j] += (a[i][k]%1000000007*b[k][j]%1000000007)%1000000007;
                c[i][j] %= 1000000007;
            }
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            a[i][j]=c[i][j];
        }
    }
}

void power(ll m[3][3], ll n){
    ll res[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    if(n>0) 
    while(n){
        
        if(n%2==1){
            mul_matrix(res,m);
        }
        mul_matrix(m,m);
        n = n/2;
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            m[i][j]=res[i][j];
        }
    }
}



ll fibosum(ll n){
    if(n<=0) return 0;
    ll ini[3]={1,0,1};
    ll m[3][3] = {{1,0,0},{1,0,1},{1,1,1}};
    power(m,n-1);
    ll res = (m[0][0] + m[2][0])%1000000007;
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        long long n,m;
        cin>>m>>n;
        ll ans = fibosum(n) - fibosum(m-1);
        if(ans<0){
            ans += 1000000007;
        }
        cout<<ans<<endl;
    }
}