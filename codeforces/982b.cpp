#include<bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

int main(){
    int n; cin>>n;

    priority_queue<pii , vector<pii> , greater<pii> >  intro;
    priority_queue<pii>  extro;

    pii p;
    for(int i=1; i<=n; i++){
        cin>>p.first;
        p.second = i;
        intro.push(p);
    }

    string s;
    cin>>s;

    int len = s.length();

    for(int i=0; i<len; i++){
        if(s[i]=='0'){
            p = intro.top(); intro.pop();
            extro.push(p);
            cout<<p.second<<" ";
        }else{
            p = extro.top(); extro.pop();
            //extro.push(p);
            cout<<p.second<<" ";
        }
    }
    cout<<"\n";

}