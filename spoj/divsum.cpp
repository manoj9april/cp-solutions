#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt = 5*1e5+5;

ll sum[lmt];

void seive(){

    for(ll i=2; i<lmt; i++){
        for(ll j=2*i; j<lmt; j+=i){
            sum[j] += i;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    seive();
    sum[1]=-1;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<sum[n]+1<<"\n";
    }

}