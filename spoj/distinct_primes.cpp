#include <bits/stdc++.h>

using namespace std;

bool num[74];
vector<int> prime;

void fprime(){
    memset(num, true, sizeof num);
    for(int i=2; i<=73; i++){
        if(num[i]){
            prime.push_back(i);
            int j=i*i;
            while(j<=73){
                num[j]=false;
                j += i;
            }
        }
    }
}

int main(){
    fprime();
    vector<long long int> lucky;
    for(int i=0; i<20; i++){
        for(int j=i+1; j<20; j++){
            for(int k=j+1; k<20; k++){
                lucky.push_back(1LL*prime[i]*prime[j]*prime[k]);
            }
        }
    }
    
    sort(lucky.begin(), lucky.end());
    vector<long long int> ans;
    for(int i=0; lucky[i]<=19*23*29; i++){
        for(int j=1; j<=29; j++){
            ans.push_back(1LL*lucky[i]*j);
        }
    }
    sort(ans.begin(), ans.end());
    cout<<"size :"<<ans.size()<<"\n";
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<ans[n-1]<<"\n";
    }
} 


/*
for(int l=k+1; l<20; l++){
    lucky.push_back(1LL*prime[i]*prime[j]*prime[k]*prime[l]);
    for(int m=l+1; m<20; m++){
        lucky.push_back(1LL*prime[i]*prime[j]*prime[k]*prime[l]*prime[m]);
        for(int n=m+1; n<20; n++){
            lucky.push_back(1LL*prime[i]*prime[j]*prime[k]*prime[l]*prime[m]*prime[n]);
            for(int o=n+1; o<20; o++){
                lucky.push_back(1LL*prime[i]*prime[j]*prime[k]*prime[l]*prime[m]*prime[n]*prime[o]);
            }
        }
    }
}
*/