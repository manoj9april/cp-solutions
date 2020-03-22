#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int const lmt = 1e6+1;

int arr[lmt];
void seive(){
    //bool a[32001];
    //memset(a, true, sizeof a);
    for(ll i=2; i<lmt; i++){
        for(ll j=i; j<lmt; j+=i){
            arr[j]++;
        }
    }
}

int gcd(int a, int b){
    if(b==0) return a;

    return gcd(b, a%b);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    seive();
    int t=1; cin>>t;
    while(t--){
        ll a,b; cin>>a>>b;

        int h = gcd(a,b);
        cout<<arr[h]+1<<"\n";
    }
}