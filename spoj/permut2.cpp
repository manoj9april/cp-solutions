#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;

    while(n){
        int a[n+1],b[n+1];

        for(int i =1; i<=n; i++){
            cin>>a[i];

            b[a[i]]=i;
        }

        bool amb = true;
        for(int i=1; i<=n; i++){
            if(a[i]!=b[i]) {amb=false; break;}
        }
        
        cout<<(amb?"ambiguous":"not ambiguous")<<endl;

        cin>>n;
    }
}