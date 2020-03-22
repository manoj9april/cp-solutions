#include<bits/stdc++.h>

using namespace std;
#define ll long long
int const lmt = 1e5+6;
priority_queue<int> q;

bool check(){
    if(q.size()==0)return true;
    int d,nn;
    while(q.size()){
        d = q.top(); q.pop();
        if(q.size()<d) return false;
        while(d--){
            nn = q.top(); q.pop();
            q.push(nn-1);
        }
    }

    return true;
}

int main(){
    int n; cin>>n;
    int ele,o=0;
    for(int i=0; i<n; i++){
        cin>>ele;
        if(ele&1)o++;
        q.push(ele);
    }
    if(o%2==1){
        cout<<"No\n";
        return 0;
    }
    cout<<(check()?"Yes\n":"No\n");
}