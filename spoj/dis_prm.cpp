#include<bits/stdc++.h>

using namespace std;
int const lmt = 1e6+7;

int fac[lmt];
vector<int> sol;
void pre(){
    for(int i=2; i<lmt; i++){
        if(fac[i]==0){
            for(int j=i; j<lmt; j+=i){
                fac[j]++;
            }
        }
    }
    for(int i=2; i<lmt; i++){
        if(fac[i]>2){
            sol.push_back(i);
        }
    }
    sort(sol.begin(),sol.end());
}
int main(){
    pre();
    /*
    for(int i=0; i<10; i++){
        cout<<sol[i].second<<"\n";
    }
    */
    int t,n; cin>>t;
    while(t--){
        cin>>n;
        cout<<sol[n-1]<<"\n";
    }
}