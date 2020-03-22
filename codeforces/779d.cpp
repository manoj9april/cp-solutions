#include<bits/stdc++.h>

using namespace std;
string a,b;
int const lmt = 2e5+5;
int n,p;
int arr[lmt];

bool check(int mid){
    string c =a;
    for(int i=0; i<mid; i++){
        c[arr[i]-1]='*';
    }
    int j=0;
    for(int i=0; i<n; i++){
        if(c[i]==b[j])j++;
        if(j==p)break;
    }

    return j==p;
}

int main(){
    cin>>a>>b;
    n = a.length();
    p = b.length();
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    int lo=0,hi=n,mid;

    while(lo<=hi){
        mid = lo + (hi-lo)/2;

        if(check(mid)) lo = mid+1;
        else hi = mid-1;
    }

    cout<<hi<<"\n";
}