#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    pair<int,int> a[n];

    for(int i=0; i<n; i++){
        cin>>a[i].first;
        a[i].second = i+1;
    }

    sort(a,a+n);
    if(n<2){
        cout<<"-1\n";
        return 0;
    }
    if(n==2 && (a[0].first==a[1].first)){
        cout<<"-1\n";
        return 0;
    }

    cout<<1<<"\n";
    cout<<a[0].second<<"\n";
}