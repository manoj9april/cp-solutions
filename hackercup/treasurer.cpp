#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll const lmt = 1e6+5,mod=1e9+7;


ll n,k;
string s;
ll a[lmt];
ll ans[lmt];
int main(){
    freopen("../input5.txt","r",stdin);
    freopen("../output.txt","w",stdout);
    int t; cin>>t;
    for(int tt=1; tt<=t; tt++){
        //
        cin>>n>>k;
        cin>>s;
        for(int i=0; i<n; i++){
            a[i] = (s[i]=='A'?-1:1);
            ans[i]=0;
        }
        ll best=-2,nbest,last=0,last1=0;
        for(int i=0; i<n; i++){
            // nbest = max(a[i],best+a[i]);
            if(a[i]>=best+a[i]){
                nbest=a[i];
                last1=i;
            }else{
                nbest=best+a[i];
            }
            if(nbest>k){
                cout<<"****"<<i<<"***\n";
                while(last<=i){
                    if(a[last]==1){
                        a[last]=-1;
                        ans[last]=1;
                        last++;
                        break;
                    }
                    last++;
                }
                // last=max(last,1ll*i);
                // nbest = max(a[i],a[i]+best-2);
                if(a[i]>=best+a[i]-2){
                    nbest=a[i];
                    last=i;
                }else{
                    nbest=best+a[i]-2;
                }
            }else{
                last = last1;
            }
            best = nbest;
        }

        ll pr=2,as=0;
        for(int i=0; i<n; i++){
            // cout<<ans[i];
            if(ans[i])as += pr%mod;
            pr = (pr*2ll)%mod;
        }
        //
        cout<<"Case #"<<tt<<": ";
        //
        cout<<as;
        //
        cout<<"\n";
    }
}
