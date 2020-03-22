#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
ll a[100][100];
int main(){
    ll n,m,k,x,y;
    cin>>n>>m>>k>>x>>y;
    x--;y--;
    if(n==1){
        ll rds=k/m;
        k = k%m;
        
        cout<<(rds+(k>0))<<" "<<rds<<" ";
        cout<<(y<k?rds+1:rds)<<"\n";
        return 0;
    }
    ll rounds = k/((n-1)*m);
    for(int i=1; i<n-1; i++){
        for(int j=0; j<m; j++)
            a[i][j]+=rounds;
    }
    for(int j=0; j<m; j++){
        a[0][j] += (rounds+1)/2 ;
        a[n-1][j] += (rounds/2) ;
    }
    k = k%((n-1)*m);
    int st = (rounds%2==0? 0:n-1);
    int in;
    if(st==0)in=1;
    else in = -1;
    for( ;k; st+=in){
        for(int j=0; j<m && k; j++){
            a[st][j]++;k--;
        }
    }
    ll mn=1e18,mx=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mx = max(mx,a[i][j]);
            mn = min(mn,a[i][j]);
            //cout<<a[i][j]<<" ";
        }
        //cout<<"\n";
    }
    cout<<mx<<" "<<mn<<" "<<a[x][y]<<"\n";
}

