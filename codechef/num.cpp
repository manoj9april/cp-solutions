#include<bits/stdc++.h>

using namespace std;

long long ppow(long long a, long long b){
    if(b==0) return 1;
    long long u = ppow(a,b/2);
    if(b%2==0) return(u*u);
    else return (a*u*u);
}

void f(int a, int b, int c){
    cout<<a<<b<<c;
}

int main(){
    int a=0;
    f(a++,a++,a++);
}