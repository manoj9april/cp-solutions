#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    string a,b;
    cin>>a>>b;
    int i=a.length()-1,j=b.length()-1;
    while(i!=-1 && j!=-1){
        if(a[i]!=b[j])break;
        i--;j--;
    }
    cout<<(i+j+2)<<"\n";
}

