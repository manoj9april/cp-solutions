#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> primes;

ll const lmt = 2147483647;

void fprime(){
    ll rtn = sqrt(lmt);
    bool a[rtn+1];
    memset(a,true, sizeof a);

    for(ll i=2; i<=rtn; i++){
        if(a[i]){
            primes.push_back(i);
            for(ll j=i*i; j<=rtn; j+=i){
                a[j]=false;
            }
        }
    }
}

bool arr[1000002];

int main(){
    int t,n,m; cin>>t;
    fprime();
    while(t--){
        cin>>n>>m;
        memset(arr, true, sizeof arr);
        for(int i=0; i<primes.size(); i++){
            ll pr = primes[i];
            if(pr>m) break;
            ll st = pr*ceil(n*1.0/pr);
            for( ; st<=m; st+= pr){
                if(st!=pr) arr[st-n]=false;
            }
        }

        for(int i=n; i<=m; i++){
            if(arr[i-n]) cout<<i<<"\n";
        }
    }
}