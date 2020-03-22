#include<bits/stdc++.h>

using namespace std;
#define ll long long 

double const eps = 1e-9;

int main(){
    long double x,y;
    cin>>x>>y;
    if(x==y){
        cout<<"=\n";
        return 0;
    }else if(x==1){
        cout<<"<\n";
        return 0;
    }else if(y==1){
        cout<<">\n";
        return 0;
    }
    double a=log2(x);
    double b=log2(y);

    if(abs(x*b-y*a)<eps){
        cout<<"=\n";
        return 0;
    }

    cout<<((x*b<y*a)?">":"<")<<"\n";

}