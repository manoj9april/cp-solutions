#include<bits/stdc++.h>

using namespace std;

#define ll long long

int main(){
    #ifndef ONLINE_JUDGE
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
	#endif
    
    ll a,b,r; cin>>a>>b>>r;
    ll cnt=0;
    for(ll x = max(0ll,a-r); x<=a+r; x++){
        ll yy = r*r - (x-a)*(x-a);
        ll y = sqrt(yy);
        cnt+= max(0ll,(b+y))-max(0ll,(b-y))+1;

    }
    cout<<cnt<<"\n";
    
}


