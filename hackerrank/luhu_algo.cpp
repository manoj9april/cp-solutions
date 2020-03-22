#include <bits/stdc++.h>

using namespace std;

int main(){
    char arr[15];
    scanf("%s",arr);

    long long sum=0;
    for(int i=0; i<15; i++){
        if(i%2==0){
            int ele=0;
            ele = arr[i]-'0';
            ele = 2*ele;
            sum += ele%10;
            sum += ele/10;
        }else{
            sum += 1LL*(arr[i]-'0');
        }
    }
    //cout<<sum<<endl;
    cout<<10-(sum%10)<<"\n";
}