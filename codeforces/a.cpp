#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int a[101][101];
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>a[i][j];
            }
        }
        bool ok=true;
        for(int i=0; ok && i<n; i++){
            for(int j=1; ok && j<n; j++){
                if(a[i][j-1]!=1-a[i][j])ok=false;
            }
        }
        for(int j=0; ok && j<n; j++){
            for(int i=1; ok && i<n; i++){
                if(a[i-1][j]!=1-a[i][j])ok=false;
            }
        }
        cout<<(ok?"Yes":"No")<<"\n";
    }
}

