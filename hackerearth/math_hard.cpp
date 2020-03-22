#include<bits/stdc++.h>

using namespace std;
#define ll unsigned long long int
int const lmt=5e6+7;

ll phi[lmt];

void pre(){
    for(int i=1; i<lmt; i++){
        phi[i]=i;
    }
    for(long long int i=2; i<lmt; i++){
        if(phi[i]==i){
            for(int j=i; j<lmt; j+=i){
                phi[j] -= (phi[j]/i);
            }
        }
    }
    for(int i=1; i<lmt; i++){
        phi[i] = (phi[i]*phi[i]);
    }

    for(int i=2; i<lmt; i++){
        phi[i] += phi[i-1];
    }
}

int main(){
    pre();
    int tt=1;
    int t; scanf("%d",&t);
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        //cout<<"Case "<<tt<<": "<<(phi[b]-phi[a-1])<<"\n";
        printf("Case %d: %llu\n",tt,phi[b]-phi[a-1]);
        tt++;
    }
}

/*
5
2 5000000
5000000 5000000
4000000 5000000
4999999 5000000
4999999 4999999
*/