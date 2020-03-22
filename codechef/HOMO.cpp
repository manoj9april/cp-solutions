#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    string res;
    bool homo=false,het=false;
    map<int,int> mii;
    while(t--){
        string s; 
        int ele; 
        cin>>s>>ele;
        if(s=="insert"){
            mii[ele]++;
        }else{
            if(mii.find(ele)!=mii.end())
            {mii[ele]--;
            if(mii[ele]==0) mii.erase(ele);}
        }
        if(res=="neither"){
            
            for(auto it:mii){
                if(it.second>=2){
                    homo=true;break;
                }else homo=false;
            }
            if(mii.size()>1) het=true;
            else het=false;
        }else if(res=="homo"){
            if(s=="insert"){
                if(mii.size()>1) het=true;
                else het=false;
            }else{
                for(auto it:mii){
                    if(it.second>=2){
                        homo=true;break;
                    }else homo=false;
                }
            }
        }else if(res=="hetero"){
            if(s=="insert"){
                for(auto it:mii){
                    if(it.second>=2){
                        homo=true;break;
                    }else homo=false;
                }
            }else{
                if(mii.size()>1) het=true;
                else het=false;
            }
        }else{
            if(s=="delete"){
            
                for(auto it:mii){
                    if(it.second>=2){
                        homo=true;break;
                    }else homo=false;
                }
                if(mii.size()>1) het=true;
                else het=false;
            }
        }
        
        if(homo){
            if(het) res="both";
            else res="homo";
        }else{
            if(het) res="hetero";
            else res="neither";
        } 

        cout<<res<<"\n";
    }
}