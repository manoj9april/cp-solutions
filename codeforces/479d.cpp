#include<bits/stdc++.h>

#define s second
#define f first
using namespace std;

int const lmt = 1e9;
int main(){
    int n; cin>>n;
    
    long long a[n];
    int next[n],prev[n];

    for(int i=0; i<n; i++){
        cin>>a[i];
        next[i]=prev[i]=-1;
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(next[j]==-1){
                if((a[j]%3==0 && a[j]/3==a[i])||(a[i]%2==0 && a[i]/2==a[j])){
                    next[j]=i;
                    prev[i]=j;
                    break;
                }
            }
        }
    }
    int st;
    for(int i=0; i<n; i++){
        if(prev[i]==-1) {st=i; break;}
    }

    for(int i=0; i<n; i++){
        cout<<a[st]<<" ";

        st = next[st];
    }
    cout<<endl;
}