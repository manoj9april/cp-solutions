#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

struct st{
    int id;
    ll sum;
};

bool comp(st a, st b){
    if(a.sum==b.sum) return a.id<b.id;

    return a.sum > b.sum;
}

int main(){
    int n; cin>>n;
    st std[n];
    ll a,b,c,d;
    for(int i=0; i<n; i++){
        cin>>a>>b>>c>>d;
        std[i].sum = (a+b+c+d);
        std[i].id=i;
    }
    sort(std,std+n,comp);
    int ans=1;
    for(int i=0; i<n; i++)if(std[i].id==0){ans=i+1; break;}
    cout<<ans<<"\n";
}

