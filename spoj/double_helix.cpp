#include<bits/stdc++.h>

#define mp  make_pair

using namespace std;

typedef pair<int,int> piii;

int u_b(int t, int a[], int lo, int hi){
    while(lo<=hi){
        int mid = lo + (hi-lo)/2;
        if(t<a[mid]) hi=mid-1;
        else lo = mid+1;
    }

    return lo-1;
}

int main(){
    int n,m;
    cin>>n;
    while(n){
        vector< piii > v;
        int a[n];
        long long h=0,apre[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
            h = apre[i] = h + a[i];
        }
        
        cin>>m;
        int b[m];
        h=0;
        long long bpre[m];
        for(int i=0; i<m; i++){
            cin>>b[i];
            h = bpre[i] = h + b[i];


            int idx = u_b(b[i],a,0,n-1);
            if(a[idx]==b[i]){
                v.push_back(mp(idx,i));
            }
        }

        long long sum =0;
        long long alast=0,blast=0;

        int len = v.size();
        
        for(int i=0; i<len; i++){
            sum += max(apre[v[i].first]-alast,bpre[v[i].second]-blast);
            alast = apre[v[i].first];
            blast = bpre[v[i].second];
        }
        sum += max(apre[n-1]-alast, bpre[m-1]-blast);

        cout<<sum<<endl;

        cin>>n;
    }
}