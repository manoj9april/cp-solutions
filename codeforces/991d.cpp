#include<bits/stdc++.h>

using namespace std;

int kx[4]= {0,1,0,1};
int ky[4]= {-1,-1,0,0};

int main(){
    string s[2];
    cin>>s[0]>>s[1];
    int n = s[0].length();
    int cnt=0;
    for(int j=1; j<n; j++){
        int lt=0;
        for(int k=0; k<4; k++){
            int x = kx[k];
            int y = j+ky[k];
            if(s[x][y]=='0')lt++;
        }
        if(lt<3) continue;
        lt=3;
        for(int k=0; lt && k<4; k++){
            int x = kx[k];
            int y = j+ky[k];
            if(s[x][y]=='0'){
                s[x][y]='X'; lt--;
            }
        }
        cnt++;
    }

    cout<<cnt<<"\n";
}