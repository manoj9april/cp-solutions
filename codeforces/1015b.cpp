#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;

int main(){
    int n; cin>>n;
    string a,aa,b,bb;
    cin>>b>>a;
    aa=a;
    bb=b;
    sort(aa.begin(),aa.end());
    sort(bb.begin(),bb.end());
    if(aa!=bb){
        cout<<-1<<"\n";
        return 0;
    }
    aa=a; bb=b;
    stack<int> st;
    int cnt=0;
    for(int i=0; i<n; i++){
        if(aa[i]==bb[i])continue;
        for(int j=i+1; j<n; j++){
            st.push(j-1);
            if(bb[j]==aa[i])break;
        }
        cnt += st.size();
        while(st.size()){
            swap(bb[st.top()],bb[st.top()+1]);st.pop();
            //cout<<st.top()+1<<" "; st.pop();
        }
    }
    cout<<cnt<<"\n";
    for(int i=0; i<n; i++){
        if(a[i]==b[i])continue;
        for(int j=i+1; j<n; j++){
            st.push(j-1);
            if(b[j]==a[i])break;
        }
        while(st.size()){
            swap(b[st.top()],b[st.top()+1]);
            cout<<st.top()+1<<" "; st.pop();
        }
    }
    cout<<"\n";
    //cout<<a<<"\n"<<b<<"\n";
}

