#include<bits/stdc++.h>
 
using namespace  std;
 
typedef long long  ll;
 
#define MOD               1000000007
#define mp                   make_pair
#define pb                    push_back
 
vector<int> prime;
 
void fprime(){
    ll rtn = sqrt(2147483647);
    bool a[rtn];
    ll j;
    
    memset(a,true,sizeof(a));
    for(ll i=2; i<rtn; i++){
        if(a[i]){
            prime.pb(i);
            j=i*i;
            while(j<rtn){
                a[j] = false;
                j += i;
            }
        }
    }
}
 
int main(){
    int t; cin>>t;
    fprime();
 
    while(t--){
        int n,m;
        cin>>n>>m;
        int size = m-n+1;
        bool arr[size];
        memset(arr,true,sizeof(arr));
        int k=n;
        int ps = prime.size();
        for(int i=0; i<ps; i++){
            k=n/prime[i]; k=k*prime[i];
            while(k<n) k+=prime[i];
            while(k<=m){
                if(k!=prime[i]) arr[k-n]=false;
                k+=prime[i];
            }
        }
        for(int i=0; i<size; i++){
            if(arr[i]){
                if(i+n == 1) continue;
                cout<<i+n<<"\n";
            }
        }
        //cout<<"\n";
    }
} 
