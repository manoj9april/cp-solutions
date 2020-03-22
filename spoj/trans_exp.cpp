#include<bits/stdc++.h>

using namespace std;

int check(char ch){
    switch(ch){
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^':return 3;
        default : return 0;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        stack<char> st;
        string s;
        cin>>s;
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i]>='a' && s[i]<='z') cout<<s[i];
            else if(s[i]=='(' || st.empty()) st.push(s[i]);
            else if(s[i]==')'){
                while(st.top()!='('){
                    cout<<st.top();
                    st.pop();
                }
                st.pop();
            }else{
                while(!st.empty() && check(s[i]) <= check(st.top())){
                    cout<<st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        while(!st.empty()){
            cout<<st.top();
            st.pop();
        }

        cout<<"\n";
    }
}