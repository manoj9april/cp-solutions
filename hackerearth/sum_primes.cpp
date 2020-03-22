#include<bits/stdc++.h>

using namespace std;
int const lmt = 1e6+4;
vector<bool> pr(lmt,true);
vector<long long int> v,pre;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    v.push_back(0);
    pre.push_back(0);

    for(int i=2; i<lmt; i++){
        if(pr[i]){
            v.push_back(i);
            for(int j=2*i; j<lmt; j+=i){
                pr[j]=false;
            }
        }
    }

    for(int i=1; i<v.size(); i++){
        //cout<<pre[i-1]<<" ";
        pre.push_back(pre[i-1]+v[i]);
    }
    //cout<<endl;

    int t; cin>>t;
    while(t--){
        long long int l,r;
        cin>>l>>r;
        int lo,hi;
        lo=lower_bound(v.begin(),v.end(),l)-v.begin();
        hi=upper_bound(v.begin(),v.end(),r)-v.begin();
        cout<<(pre[hi-1]-pre[lo-1])<<"\n";
    }
}