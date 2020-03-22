#include<bits/stdc++.h>

using namespace std;

int const lmt=100;

int sum,tsum,n;
vector<int> sol;
int arr[lmt];

void call(int i){
    if(sum+arr[i]==tsum){
        sol.push_back(arr[i]);
        for(int j=0; j<sol.size(); j++){
            cout<<sol[j]<<" ";
        }cout<<"\n";
        sol.pop_back();
        return;
    }
    if(sum+arr[i]<tsum){
        sum += arr[i];
        sol.push_back(arr[i]);
        for(int j=i+1; j<n; j++){
            call(j);
        }
        sol.pop_back();
        sum -= arr[i];
    }
}

int main(){
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cin>>tsum;
    for(int i=0; i<n; i++){
        sum=0;
        call(i);
    }
}