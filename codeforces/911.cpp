#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int a[3];
    vector<bool> ck(10,false);
    cin>>a[0]>>a[1]>>a[2];
    int x[3];int k=0;
    sort(a,a+3);
    for(int i=0; i<10 && k<3; i++){
        if(!ck[i]){
            x[k]=i;
            for(int j=i; j<10; j+=a[k]){
                ck[j]=true;
            }
            k++;
        }
    }
    for(int i=0; i<10; i++){
        if(!ck[i]){
            cout<<"NO\n";
            return 0;
        }
    }
    cout<<"YES\n";
    return 0;
}

