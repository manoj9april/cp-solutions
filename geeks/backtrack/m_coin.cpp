#include<bits/stdc++.h>

using namespace std;

int const lmt=10;
int n;
int sol[lmt][lmt];

bool check(int x, int y){
    if(x>=0 && y>=0 && x<n && y<n) return true;

    return false;
}

bool canplace(int x,int y){
    return true;
}

void row(int i, int cnt){

    for(int j=0; j<n; j++){
        if(canplaceat(i,j)){

        }
    }
}

int main(){

}