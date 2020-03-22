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
        ll k,f,s;
        cin>>k>>f>>s;
        if(k<=7){
            ll ans =0;
            ans += f+s;
            if(k>2){
                for(int i=1; i+2<=k; i++){
                    ans += (ans%10);
                }
            }

            cout<<(ans%3==0?"YES\n":"NO\n");
        }else{
            ll ans=0;
            int a[7];
            a[0]=f;
            a[1]=s;
            a[2]= (f+s)%10;
            for(int i=3; i<7; i++){
                a[i] = (2*a[i-1])%10;
                ans += a[i]%3;
                ans %=3;
            }
            ll four = ans;
            ans += a[0]+a[1]+a[2];
            ans %= 3 ;
            k = k-7;
            ans += (four*((k/4)%3))%3;
            k = k%4;
            for(int i=1; i<=k; i++){
                ans += a[i+2];
            }

            cout<<(ans%3==0?"YES":"NO")<<"\n";
                
        }
    }
}