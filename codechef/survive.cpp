#include<bits/stdc++.h>

using namespace std;

typedef long long  ll;

#define MOD               1000000007
#define scll(t)               scanf("%lld",&t)
#define sc(t)                 scanf("%d",&t)
#define max(a,b)         (a>=b?a:b)
#define min(a,b)          (a<b?a:b)
#define gc                    getchar_unlocked
#define mp                   make_pair
#define pb                    push_back
#define Size(a)            int((a).size())
#define F                     first
#define S                     second

int main(){
    int t; cin>>t;
    while(t--){
        int n,k,s;
        cin>>n>>k>>s;
        int ans = k*s;
        if(ans%n!=0){
            ans /= n;
            ans++;
        }else{
            ans /= n;
        }

        if(ans <=(s-s/7)){
            if(s>6){
                if((n-k)*6 >= k)
                    cout<<ans<<"\n";
                else{
                    cout<<"-1\n";
                }
            }else{
                cout<<ans<<"\n";
            }
            
        }else{
            cout<<"-1\n";
        }
    }
}