#include<bits/stdc++.h>

using namespace std;

int n,k;
int price[101];
int dp[101][101];
int packet[101][101];

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;

        for(int i=1; i<=k; i++){
            cin>>price[i];
        }
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                dp[i][j]=100000000;
                packet[i][j]=0;
            }
        }
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                if(i==0){
                    dp[i][j]=0;
                    //packet[i][j]=0;
                }else if(j==0){
                    continue;
                }if(j>i){
                    dp[i][j]=dp[i][j-1];
                    packet[i][j]=packet[i][j-1];
                }
                else{/*
                    for(int p=j; p>=1; p--){
                        if(price[p]!=-1 && packet[i-p][p]<n && dp[i][j]>dp[i-p][p]+price[p]){
                            dp[i][j] = dp[i-p][p]+price[p];
                            packet[i][j]=packet[i-p][j]+1;
                        }
                    }*/
                    if(price[j]!=-1 && packet[i-j][j]<n){
                        dp[i][j] = dp[i-j][j]+price[j];
                        packet[i][j]=packet[i-j][j]+1;

                    }
                    if(packet[i][j-1]<n && dp[i][j]>=dp[i][j-1]){
                        dp[i][j]=dp[i][j-1];
                        packet[i][j] = packet[i][j-1];
                    }if(dp[i][j]==100000000){
                        dp[i][j]=dp[i][j-1];
                        packet[i][j]= packet[i][j-1];
                    }
                }
            }

            /*
        	if(i==0){
        		for(int j=0; j<=k; j++)dp[i][j]=0;
        	}
            for(int j=0; j<=i; j++){
                //if(i==0)dp[i][j]=0;
                if(j==0) { dp[i][j]=100000000; continue;}
                else if( price[j]!=-1 && (price[j]+dp[i-j][j] <= dp[i][j-1])){
                    dp[i][j] = price[j]+dp[i-j][j];
                    
                }else{
                    dp[i][j]=dp[i][j-1];
                }
            }*/
        }
        /*
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){
                if(dp[i][j]==100000000)
                cout<<"# ";
                else 
                cout<<dp[i][j]<<" ";
            }cout<<"\n";
        }
        for(int i=0; i<=k; i++){
            for(int j=0; j<=k; j++){ 
                cout<<packet[i][j]<<" ";
            }cout<<"\n";
        }*/
        int ans=100000000;
        for(int j=0; j<=k; j++){
            ans = min(dp[k][j],ans);
        }
        cout<<(ans==100000000?-1:ans)<<endl;
    }
}