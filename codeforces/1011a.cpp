#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1001;
int occ[26];
int main(){
    int n,k;
    string s;
    cin>>n>>k;
    cin>>s;
    
    for(int i=0; i<n; i++){
        occ[s[i]-'a']++;
    }
    int cnt=0,val=0;
    bool last = false;
    if(occ[0]){val=1;cnt++;}
    else if  (occ[1]){val=2;cnt++;last=true;}
    for(int i=2; cnt<k && i<26; i++){
        if(last){last=false;continue;}
        if(occ[i]){
            last=true;
            val += i+1;
            cnt++;
        }else{
            last=false;
        }
    }
    cout<<(cnt<k?-1:val)<<"\n";
}

