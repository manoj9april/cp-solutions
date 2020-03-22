#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;

    while(t--){
        int k; cin>>k;

        int n=1;
        while(k >= n*(n+1)/2) n++;
        int num,den,sum =n+1;
        int r = n;
        int pre = r*(r-1)/2;

        if(r%2==0){
            num = k - pre;
            den = sum - num;
        }else{
            den = k-pre;
            num = sum - den;
        }

        cout<<"TERM "<<k<<" IS "<<num<<"/"<<den<<endl;

    }
}