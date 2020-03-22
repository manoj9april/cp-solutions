#include<bits/stdc++.h>

using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    bool arr[n+1];
    memset(arr, false, sizeof arr);
    int cnt=0; 
    string s; int j;
    while(k--){
        cin>>s;
        if(s[4]=='K'){
            cin>>j;
            if(arr[j]){
                cnt--;
                arr[j]=false;
            }else{
                arr[j]=true;
                cnt++;
            }
        }else{
            cnt=0;
            memset(arr, false, sizeof arr);
        }

        cout<<cnt<<"\n";
    }
}

