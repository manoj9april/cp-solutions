#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    ll n,x,y,a=0,b=0,cnt=0;
    cin>>n>>x>>y;
    string s; cin>>s;
    for(int i=1; i<n; i++){
        if(s[i]!=s[i-1])cnt++;
    }
    a = (cnt+1)/2;
    if(cnt==0 && s[0]=='1'){
        cout<<"0\n";
        return 0;
    }
    if(cnt%2==0 && s[0]=='0')a++;

    a--;b++;
    ll val,ans=1e15;
    //cout<<cnt<<"\n";
    for(int i=a; i!=-1; a--,b++,i--){
        val = a*x + b*y;
        //cout<<a<<" "<<b<<"\n";

        ans = min(ans,val);
    }

    cout<<ans<<"\n";
}