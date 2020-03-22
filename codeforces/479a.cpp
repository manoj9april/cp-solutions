#include<bits/stdc++.h>

using namespace std;
int c[26][26];

int main(){

    int n;
    string s;
    cin>>n>>s;

    char maxi,maxj;
    int maxx=0;
    for(int i=0; i<n-1; i++){
        c[s[i]-'A'][s[i+1]-'A']++;
        if(c[s[i]-'A'][s[i+1]-'A']>maxx){
            maxx = c[s[i]-'A'][s[i+1]-'A'];
            maxi = s[i];
            maxj = s[i+1];
        }
    }

    cout<<maxi<<maxj<<"\n";
}