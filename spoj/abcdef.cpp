#include<bits/stdc++.h>

const int lmt=1e6+10;
using namespace std;
int a[105];
int L[lmt],R[lmt];
int dL[lmt],dR[lmt];
int dLfre[lmt],dRfre[lmt];

int main(){
    int n;cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    //calculating values of LHS and Rhs
    int x=0,y=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                L[x++]=a[i]*a[j]+a[k];  
                if(a[i]!=0){
                    R[y++]=a[i]*(a[j]+a[k]);
                }
            }
        }
    }

    sort(L,L+x);
    sort(R,R+y);

    int dli=0; dL[dli]=L[0]; dLfre[dli]=1;
    for(int i=1; i<x; i++){
        if(L[i]==dL[dli]){
            dLfre[dli]++;
        }else{
            dli++;
            dL[dli]=L[i];
            dLfre[dli]=1;
        }
    }

    int dri=0; dR[dri]=R[0]; dRfre[dri]=1;
    for(int i=1; i<x; i++){
        if(R[i]==dR[dri]){
            dRfre[dri]++;
        }else{
            dri++;
            dR[dri]=R[i];
            dRfre[dri]=1;
        }
    }

    long long ans=0;
    for(int i=0,j=0; i<=dli && j<=dri;){
        if(dL[i]==dR[j]){
            ans += (long long)dLfre[i]*dRfre[j];
            i++;j++;
        }else if(dL[i]<dR[j]) i++;
        else j++;
    }

    cout<<ans<<endl;
}