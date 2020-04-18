void kmp(int* f, string str){
    
    int len = str.length(), j=0;
    f[0]=0;
    for(int i=1; i<len; i++){

        while(j>0 && str[i]!=str[j]){
            j = f[j-1];
        }
        
        if(str[i]==str[j])++j;
        f[i]=j;
    }
}
