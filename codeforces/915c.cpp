#include<bits/stdc++.h>

using namespace std;
#define ll long long

int const lmt = 1e5+7;
vector<int> ac(10,0),bc(10,0);
string ans="",temp="";

void make(){
    bc = ac;
    for(int i=0; i<=9; i++){
        while(bc[i]){
            temp += char(i+'0');
            bc[i]--;
        }
    }
}   

int main(){
    string a,b;
    cin>>a>>b;
    int n = a.length();
    int m = b.length();
    if(n<m){
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        cout<<a<<"\n";
        return 0;
    }
    for(int i=0; i<n; i++){
        ac[a[i]-'0']++;
        bc[b[i]-'0']++;
    }
    
    for(int i=0; i<n; i++){
        
        for(int j=9; j>=0; j--){
            if(!ac[j]) continue;
            temp = ans;
            temp += char(j+'0');
            ac[j]--;

            make();
            if(temp<=b){
                ans += char(j+'0'); break;
            }else{
                ac[j]++;
            }
        }
    }
    
    cout<<ans<<"\n";    
}