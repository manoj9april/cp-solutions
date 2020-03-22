#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;

int const lmt=15;
ll g[3],a[3],nf[3],n,vis[lmt],sum=0,ans=0;

void sit(int arr[],int ii, int p, int sum){
    if(ii==3){
        ans=max(ans,1ll*sum);
        // cout<<"*";
        return;
    }
    int gn = arr[ii];
    if(p>=nf[gn]){
        sit(arr,ii+1,0,sum);
        return;
    }
    int mn1=0;
    int mn2=0;
    for(int i=g[gn]; i<=n; i++){
        if(!vis[i]){
            mn1=i;break;
        }
    }
    for(int i=g[gn]-1; i>=1; i--){
        if(!vis[i]){
            mn2=i;break;
        }
    }
    if(mn1 && mn2 && mn1-g[gn]<=g[gn]-mn2){
        vis[mn1]=1;
        sum+=mn1-g[gn]+1;
        sit(arr,ii,p+1,sum);
        vis[mn1]=0;
        sum-=mn1-g[gn]+1;
    }
    if(mn1 && mn2 && mn1-g[gn]>=g[gn]-mn2){
        vis[mn2]=1;
        sum+=g[gn]-mn2+1;
        sit(arr,ii,p+1,sum);
        vis[mn2]=0;
        sum-=g[gn]-mn2+1;
    }
    else if(mn1){
        vis[mn1]=1;
        sum+=mn1-g[gn]+1;
        sit(arr,ii,p+1,sum);
        vis[mn1]=0;
        sum-=mn1-g[gn]+1;
    }else if(mn2){
        vis[mn2]=1;
        sum+=g[gn]-mn2+1;
        sit(arr,ii,p+1,sum);
        vis[mn2]=0;
        sum-=g[gn]-mn2+1;
    }
}

int main(){
    #ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif
    
    int T; cin>>T;
    for(int t=1; t<=T; t++){
        ll ans;
        cin>>n;
        for(int i=0; i<3; i++)cin>>g[i]>>nf[i];
        sum=0;
        for(int i=0; i<3; i++){
            for(int j=0;j<3; j++){
                if(i!=j)
                for(int k=0; k<3; k++){
                    if(k!=i && k!=j){
                        //cout<<i<<" "<<j<<" "<<k<<"\n";
                        int arr[3]={i,j,k};
                        sit(arr,0,0,0);
                    }
                }
            }
        }
        cout<<"#"<<t<<" ";
        cout<<ans<<"\n";
    }
}
