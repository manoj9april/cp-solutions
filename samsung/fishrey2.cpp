#include<iostream>
#include<bits/stdc++.h>

#define ll long long
using namespace std;
using namespace std::chrono; 

int const lmt=100;
ll g_idx[3],nf[3],gvis[3],ans,spotvis[lmt],n;
ll const mxval=1e9+3;

void reset(int gn){
    for(int i=1; i<=n; i++){
        if(spotvis[i]==gn)spotvis[i]=0;
    }
}

int sit(int gn, ll &sum, int &pos1, int &pos2){
    int left=g_idx[gn],right=g_idx[gn];
    ll rtdiff,ldiff;
    for(int i=1; i<nf[gn]; i++){
        rtdiff=ldiff=mxval;
        if(!spotvis[g_idx[gn]]){
            sum++;
            spotvis[g_idx[gn]]=gn+1;
            continue;
        }
        while(left>=1 && spotvis[left])left--;
        while(right<=n && spotvis[right])right++;

        if(left>=1) ldiff  = g_idx[gn]-left+1;
        if(right<=n) rtdiff  = right - g_idx[gn]+1;

        if(ldiff  == rtdiff){
            sum += 2*ldiff;
            spotvis[left]=spotvis[right]=gn+1;
            if(i==nf[gn]-1)return 1;
            i++;
        }else if(ldiff<rtdiff){
            sum += ldiff;
            spotvis[left]=gn+1;
        }else{
            sum += rtdiff;
            spotvis[right]=gn+1;
        }
    }

    while(left>=1 && spotvis[left])left--;
    while(right<=n && spotvis[right])right++;

    if(left>=1) ldiff  = g_idx[gn]-left+1;
    if(right<=n) rtdiff  = right - g_idx[gn]+1;

    if(ldiff  == rtdiff){
        sum += ldiff;
        pos1=left; pos2=right;
        return 2;
    }else if(ldiff<rtdiff){
        sum += ldiff;
        spotvis[left]=gn+1;
        return 1;
    }else{
        sum += rtdiff;
        spotvis[right]=gn+1;
        return 1;
    }
}

bool cc=1;
void call(int arr[], int ii, ll sum){
    if(ii==3){
        
        // if(cc && sum==24){
        //     cout<<arr[0]<<arr[1]<<arr[2]<<"\n";
        //     for(int i=1; i<=n; i++){
        //         cout<<spotvis[i]<<" ";
        //     }
        //     cout<<"\n";
        //     cc=0;
        // }
        //cout<<ans<<"----"<<sum<<"===\n";
        ans = min(ans,sum);
        //cout<<ans<<"___"<<sum<<"===\n";
        return;
    }
    int gn = arr[ii];
    int pos1,pos2;

    int npos = sit(gn,sum,pos1,pos2);
    if(npos==1){
        call(arr,ii+1,sum);
    }else{
        spotvis[pos1]=gn+1;
        call(arr,ii+1,sum);
        spotvis[pos1]=0;

        spotvis[pos2]=gn+1;
        call(arr,ii+1,sum);
        spotvis[pos2]=0;
    }

    reset(gn+1);
}

int main(){
    /*#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
	#endif*/
    
    auto start = high_resolution_clock::now();

    int T; cin>>T;
    for(int t=1; t<=T; t++){
        cin>>n;
        for(int i=0; i<3; i++){
            cin>>g_idx[i]>>nf[i];
        }
        ans = mxval;
        //cout<<ans<<"\n";
        // for(int i=1; i<=n; i++)cout<<spotvis[i]<<" ";
        // cout<<"\n";

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(j!=i)
                for(int k=0; k<3; k++){
                    if(k!=j && k!=i){
                        int arr[4]={i,j,k,5};
                        call(arr,0,0);
                    }
                }
            }
        }
        cout<<"#"<<t<<" ";
        cout<<ans<<"\n";
    }

    auto stop = high_resolution_clock::now(); 

    auto duration = duration_cast<microseconds>(stop - start); 
  
    cout << "Time: "
         << duration.count()/1000/1000.0 << " seconds" << endl; 
    
}

/*

#1 18
#2 18
#3 32
#4 88
#5 331


other
#1 18
#2 25
#3 57
#4 86
#5 339

*/

