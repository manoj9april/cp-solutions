#include<bits/stdc++.h>
 
using namespace std;
 
long long int mm = 1000000007;
int main(){
    int t; cin>>t;
 
    while(t--){
 
        long long int n,m; cin>>n>>m;
        long long int res[n+1];
        //long long int a[m][n+1];
        //memset(a,0,sizeof(a[0][0])*m*(n+1));
        memset(res,0,sizeof(res[0])*(n+1));

        long long b[m][4];
        //b[m]={0,-1,-1,0};
        for(int i=0; i<m; i++){
            cin>>b[i][0]>>b[i][1]>>b[i][2];
            b[i][3]=1;
            //b[i][4]=0;
        }
        for(int i=m-1; i>=0; i--){
            if(b[i][0]==2){
                long long int ll = b[i][1]-1;
                long long int rr = b[i][2]-1;
                for(int k=ll; k<=rr; k++){
                    b[k][3] += b[i][3];
                    //b[k][3] += (b[i][3]%mm)%mm;
                }
            }
        }
        for(int i=0; i<m; i++){
            if(b[i][0]==1){
                long long ll=b[i][1]-1;
                long long rr=b[i][2];
                res[ll] += b[i][3];
                //res[ll] += (b[i][3]%mm)%mm;
                res[rr] -= b[i][3];
                //res[rr] -= (b[i][3]%mm)%mm;
            }
        }
        long long sum=0;
        for(int i=0; i<n; i++){
            //sum = (sum%mm+(res[i]%mm))%mm;
            sum += res[i]%m;
            //cout<<sum<<" ";
            long long int l=sum%(mm);
            printf("%d ",l);
        }
        printf("\n");
    }
}
