#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
map<int, int> my;

int main(){
    int n; cin>>n;
    int a[n]; 
    for(int i=0; i<n; i++){
        cin>>a[i];
        my[a[i]]++;
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        ll j=1;
        bool ok=false;
        while(j<=2e9 && !ok){
            if(j>=a[i] && my[j-a[i]]){
                ok=true;
                if(j-a[i] == a[i] && my[a[i]]<2)ok=false;
            }
            //cout<<j<<" ";
            j <<= 1;
            
        }
        //cout<<"\n";
        if(!ok)cnt++;
    }

    cout<<cnt<<"\n";
}

