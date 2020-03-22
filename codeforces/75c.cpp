#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
vector<int> v;
int main(){
    int a,b;
    cin>>a>>b;
    int g = gcd(a,b);
    int rt=sqrt(g);
    for(int i=1; i<=rt; i++){
        if(g%i==0){
            v.push_back(i);
            v.push_back(g/i);
        }
    }
    sort(v.begin(),v.end());
    int n,lo,hi,ans,idx;
    cin>>n;
    while(n--){
        cin>>lo>>hi;
        idx = upper_bound(v.begin(),v.end(),hi)-v.begin();
        if(v[idx-1]>=lo && v[idx-1]<=hi){
            cout<<v[idx-1]<<"\n";
        }else{
            cout<<"-1\n";
        }
    }
}