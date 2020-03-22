#include<bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        string num;
        cin>>num;
        int len=num.length();


		int k=0;
		while(k!=len-1){
			if(num[k]=='0') k++;
			else break;
		}
		num = num.substr(k);
		len=num.length();
        //cout<<num<<"\n";
		
		bool palin = true, allNine=true;
    
        for(int i=len-1; i>=len/2; i--){
            if(num[len-1-i]!=num[i]) palin = false;
            if(num[len-1-i]!='9')allNine=false;
        }
        if(palin){
            if(num[len-1]!='9'){
                num[len-1] += 1;
            }else if(allNine && num[len/2]=='9'){
                char ch[len-1];
                memset(ch,'0',len-1);
                cout<<"1"<<ch<<"1\n";
                continue;
            }
            else{
                int j=0;
                while(num[len-1-j]=='9'){
                    num[len-1-j]='0';
                    j++;
                }
                num[len-1-j] += 1;
            }
        }
        //cout<<num<<"\n";
        for(int i=len-1; i>=len/2; i--){
            if(num[len-1-i]!=num[i]){
                if(num[len-1-i]<num[i]){
                    if(num[i-1]!='9'){
                        num[i-1] += 1;
                    }else{
                        int j=1;
                        while(num[i-j]=='9'){
                            num[i-j]='0';
                            j++;
                        }
                        num[i-j] += 1;
                    }
                    num[i]=num[len-1-i];
                }else{
                    num[i]=num[len-1-i];
                }
                
            }
            if(num[len-1-i]!=num[i]){
                if(num[len-1-i]<num[i]){
                    if(num[i-1]!='9'){
                        num[i-1] += 1;
                    }else{
                        int j=1;
                        while(num[i-j]=='9'){
                            num[i-j]='0';
                            j++;
                        }
                        num[i-j] += 1;
                    }
                    num[i]=num[len-1-i];
                }else{
                    num[i]=num[len-1-i];
                }
            }    
        }
        cout<<num<<"\n";
    }
}