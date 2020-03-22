#include<bits/stdc++.h>
 
using namespace std;
 
int main(){
    int t; cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len = s.length();
        bool ispre[26];
        memset(ispre, false, sizeof(ispre));
        vector<int>  v[26];
        for(int i=0; i<len; i++){
            ispre[s[i]-'a'] = true;
            v[s[i]-'a'].push_back(i+1);
        }
        int sp;
        long long ans =0;
        for(int i=0; i<26; i++){
            ans += (v[i].size()%2);
            
        }
        if(ans>1){
            cout<<"-1\n";
        }else{
            int j=0;
            
            for(; j<26;j++){
                if(v[j].size()%2==1) sp =j;
                if(ispre[j] && v[j].size()>1){
                    int jj = v[j].size()/2;
                    for(int k=0; k<jj; k++){
                        cout<<v[j].back()<<" ";
                        v[j].pop_back();
                    }
                }
            }
            if(ans==1){
            cout<<v[sp].back()<<" "; v[sp].pop_back();
            }
            
            for( j=25; j>=0;j--){
                if(ispre[j]){
                    int jj = v[j].size();
                    for(int k=0; k<jj; k++){
                        cout<<v[j].back()<<" ";
                        v[j].pop_back();
                    }
                }
            }
            cout<<"\n";
        }
        
    }
} 