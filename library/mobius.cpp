#include<bits/stdc++.h>

using namespace std;

int const lmt = 1e6+1;
int mo[lmt];
void pre(){
    mo[1]=1;
    bool prime[lmt];
    //memset(prime, false, prime);

    for(int i=1; i<lmt; i++){
        mo[i]=1;
        prime[i]=true;
    }
    for(int i=2; i*i<lmt; i++){

        if(prime[i]){
            for(int j=i; j<lmt; j+=i){
                if((j/i)%i==0){
                    mo[j]=0;
                }
                mo[j] *= -1;
                prime[j]=false;
            }
        }
    }
}


void cal_mob(){
    int spf[lmt];
    bool prime[lmt];
    for(int i=1; i<lmt; i++){
        spf[i]=i;
        prime[i]=true;
    }
    for(int i=2; i*i<lmt; i++){
        if(prime[i]){
            for(int j=i; j<lmt; j+=i){
                if(spf[j]==j) spf[j]=i;
                prime[j]=false;
            }
            
        }
    }

    mo[1]=1;
    for(int i=2; i<lmt; i++){
        if(spf[i]==spf[i/spf[i]])  mo[i]=0;
        else mo[i] = -mo[i/spf[i]];
    }
}
int main(){
    //pre();
    cal_mob();
    for(int i=1; i<10; i++) cout<<mo[i]<<endl;
}