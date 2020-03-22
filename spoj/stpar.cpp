#include<bits/stdc++.h>

using namespace std;

int main(){
    int n; cin>>n;

    while(n){
        stack<int> s,g;
        s.push(INT_MAX);
        int ele=-1,prev,j=1;
        bool ok =true;
        for(int i=0; i<n; i++){
            prev = ele;
            cin>>ele;
            
            if(ele==j) { j++;}
            else if(ele<s.top())
                s.push(ele);
            else if (j == s.top()){
                while(s.top()!=INT_MAX){
                    j=s.top()+1;
                    s.pop();
                }
                j++;
            }
            else {ok=false;  }
        }

        cout<<(ok?"yes":"no")<<endl;

        cin>>n;
    }
}