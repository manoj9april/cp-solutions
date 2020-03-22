#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

map<int,int> my,ol;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n];
    ll sum=0,cnt=0;
    for(int i=0; i<n; i++){
        cin>>a[i];
        //if(a[i]==m)cnt++;
    }
    int j=0;
    my[0]=1;
    while(j<n){
        if(a[j]==m)break;
        if(a[j]>m) sum++;
        else if (a[j]<m)sum--;
        my[sum]++;
        j++;
    }
    ll ans=0;
    while(j<n){
        ol=my;
        ll ns=0;
        bool first=true;
        while(j<n){
            if(!first && a[j]==m){
                if(ns>=1 && ns<=2)cnt++;
                break;
            }
            if(a[j]>m) ns++;
            else if (a[j]<m)ns--;
            ans += ol[sum+ns];
            ans += ol[sum+ns-1];
            if(ol[sum+ns] || ol[sum+ns-1])cout<<j+1<<" "<<ol[sum+ns]+ol[sum+ns-1]<<"\n";
            my[sum+ns]++;
            j++;
            first=false;
        }
        sum+=ns;
    }
    cout<<"ans=";
    cout<<ans+cnt<<"\n";
}

