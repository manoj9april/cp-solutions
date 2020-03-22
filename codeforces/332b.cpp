#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 2e5+4;

ll lt[lmt],rt[lmt];
ll a[lmt];
int main(){
    ll n,k,neg=-2e8+2;
    cin>>n>>k;
    ll sum=0,ans=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        sum+=a[i];
        if(i<k-1){
            lt[i]=neg;
        }else{
            ans  = max(ans,sum);
            lt[i]=ans;
            sum-=a[i-k+1];
        }
    }
    sum=0;
    ll idx=0,gs=0; ans=0;
    for(int i=n-1; i>=k; i--){
        sum+=a[i];
        if(i<=n-k){
            gs = max(sum,gs);
            if(lt[i-1]+gs>=ans){
                ans=lt[i-1]+gs;
                idx=i;
            }
            sum-=a[i+k-1];
        }
    }
    int b=-1,aa=idx-k;
    sum=0;
    for(int i=idx; i<n; i++){
        sum += a[i];
        if(i>=idx+k-1){
            if(lt[idx-1]+sum==ans){b=i-k+1; break;}
            sum-=a[i-k+1];
        }
    }aa++; b++;
    cout<<aa<<" "<<b<<"\n";
}

