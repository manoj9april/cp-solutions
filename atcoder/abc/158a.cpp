#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
  string s; cin>>s; 
  set<char> st;
  for(int i=0; i<3; i++) st.insert(s[i]);
  cout<<(st.size()!=1?"Yes":"No");
}