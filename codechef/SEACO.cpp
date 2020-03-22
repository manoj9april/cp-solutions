#include<bits/stdc++.h>
 
using namespace std;
 
long long int mm = 1000000007;
int main(){
    int t; cin>>t;
 
    while(t--){
 
        long long int n,m; cin>>n>>m;
        long long int res[n+1];
        long long int a[m][n+1];
        memset(a,0,sizeof(a[0][0])*m*(n+1));
        memset(res,0,sizeof(res[0])*(n+1));
        //cout<<a[1][1];
        int type,l,r,ll,rr;
        for(int i=0; i<m; i++){
            cin>>type>>l>>r;
            ll=l-1; rr=r-1;
            if(type==1){
                a[i][ll]+=1;res[ll]++;//res[ll] = (res[ll]%mm + 1)%mm;
                a[i][r]-=1;res[r]--;// = (res[r]%mm - 1)%mm;
            }else{
                for(int k=0; k<n; k++){
                    long long int sum=0;
                    for(int j=ll; j<=rr; j++){
                        //sum = (sum+a[k][j]%mm)%mm;
                        sum += a[j][k];
                    }
                    a[i][k]=sum; //res[k] = (res[k] + sum%mm)%mm;
                    res[k] += sum;
                }
            }
        }
 
        /*long long int value=0;
        for(int i=0; i<n; i++){
            long long int sum=0;
            for(int j=0; j<m; j++){
                //sum = (sum+a[i][j]%mm)%mm;
                sum +=a[j][i];
            }
            //value +=sum;
            value = (value+sum%mm)%mm;
            cout<<value<<" ";
        }*/
        long long int value=0;
        for(int i=0; i<n; i++){
            //value = (value + res[i]%mm)%mm;
            value += res[i];
            cout<<value<<" ";
        }
        cout<<"\n";
        //cout<<"\n";
        //for(int i=0; i<n; i++)
    }
    //return 0;
}