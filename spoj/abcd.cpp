#include<bits/stdc++.h>

using namespace std;

#define ll long long

int const lmt = 2501;
int a[lmt],b[lmt],c[lmt],d[lmt], f[lmt*lmt], s[lmt*lmt];

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
    int k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            f[k] = -a[i]-b[j];
            k++;
        }
    }
    k=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            s[k] = c[i]+d[j];
            k++;
        }
    }
    sort(f,f+k);
    sort(s,s+k);
    int cnt=0;
    for(int i=0; i<k; i++){
        cnt += (upper_bound(s,s+k,f[i])-lower_bound(s,s+k,f[i]));
        //cout<<cnt<<"\n";
    }

    cout<<cnt<<"\n";
}