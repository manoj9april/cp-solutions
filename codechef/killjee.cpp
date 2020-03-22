#include <bits/stdc++.h>

using namespace std;

#define  pb  push_back

int main(){
    string s;
    cin>>s;
    vector<string> v;
    int len = s.length();
    for(int i=0; i<len; i++){
        for(int j=1; i+j<=len; j++){
            v.pb(s.substr(i,j));
        }
    }
    sort(v.begin(), v.end());
    string res="";
    int l = v.size();
    for(int i=0; i<l; i++){
        res += v[i];
    }

    int q; cin>>q;
    long long p,m,k,g=0;
    while(q--){
        cin>>p>>m;
        k = (p*g)%m + 1;
        cout<<res[k-1]<<"\n";
        g += (int)res[k-1];
    }
    
}