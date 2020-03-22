#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;

    stack<char> st;
    for(int i=0; i<n; i++){
        if(s[i]==')' && !st.empty() && st.top()=='(') st.pop();
        else st.push(s[i]);
    }
    int len = st.size();
    if(len==0){
        cout<<0<<"\n";
    }else{
        char l,f = st.top();
        while(!st.empty()){
            l = st.top();
            st.pop(); 
        }
        cout<<(f==l?1:2)<<"\n";
    }
    //cout<<solve(0)<<"\n";
}