#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 3e5+7;
int const inf=4e5+7;
int rt[lmt],lt[lmt];
int a[lmt],vl[lmt];
int main(){
    int n; cin>>n;
    string s;
    for(int i=0; i<n; i++){
        cin>>s;
        int len = s.length();
        int val=0;
        int neg=0;
        for(int j=0; j<len; j++){
            val += (s[j]=='('?1:-1);
            neg=min(val,neg);
        }
        if(neg<0 && val==neg){rt[-val]++; a[i]=2; vl[i]=-val;}
        else if(neg==0 && val>0) {lt[val]++;a[i]=1; vl[i]=val;}
        else if(neg==0 && val==0) {lt[val]++;rt[val]++; a[i]=3; vl[i]=0;}
    }
    ll ans=0;
    for(int i=0; i<n; i++){
        if(a[i]==1){
            ans += 1LL*rt[vl[i]];
        }else if(a[i]==2){
            //ans += 1LL*lt[vl[i]];
            ;
        }else if(a[i]==3){
            ans += 1LL*rt[0];
        }
    }
    cout<<ans<<"\n";
}