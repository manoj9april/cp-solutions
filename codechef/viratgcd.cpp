#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e5+1;
int mo[lmt];

void cal_mob(){
    int spf[lmt];
    bool prime[lmt];
    for(int i=1; i<lmt; i++){
        spf[i]=i;
        prime[i]=true;
    }
    for(int i=2; i*i<lmt; i++){
        if(prime[i]){
            for(int j=i; j<lmt; j+=i){
                if(spf[j]==j) spf[j]=i;
                prime[j]=false;
            }
            
        }
    }

    mo[1]=1;
    for(int i=2; i<lmt; i++){
        if(spf[i]==spf[i/spf[i]])  mo[i]=0;
        else mo[i] = -mo[i/spf[i]];
    }
}

long long ncr(long long n){
    if(n<2) return 0;

    return (n*(n-1)/2);
}



int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cal_mob();

    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;

        // cal fun
        int fun[lmt]={0};
        for(int i=k; i<lmt; i++){
            for(int j=i; j<lmt; j+=i){
                fun[j] += mo[j/i];
            }
        }

        int fre[lmt]={0};
        int ele,mx=0;
        for(int i=0; i<n; i++){
            cin>>ele;
            fre[ele]++;
            mx = max(mx,ele);
        }

        // calculate multiples of i
        int mul[lmt]={0};
        mul[1]=n;
        for(int i=2; i<lmt; i++){
            for(int j=i; j<lmt; j+=i){  // j is a mul of i
                mul[i] += fre[j];
            }
        }

        // cal ans

        long long ans =0;

        for(int i=k; i<=mx; i++){
            ans += fun[i]*ncr(mul[i]);
        }

        cout<<ans<<endl;
    }
    
}