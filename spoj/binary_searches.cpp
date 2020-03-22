

////  returns index of first true  else  v.end() if all false

int lb(int target){
    int mid,lo=0,hi=rt.size()-1;

    while(lo<=hi){
        mid = lo+ (hi-lo)/2;
        if(target+rt[mid] <= b) lo =mid+1;   
        else hi =mid-1;
    }
    return hi;
}


/////// returns index of last true  else -1  if all false

int ub(int target){
    int mid,lo=0,hi=rt.size()-1;

    while(lo<=hi){
        mid = lo+ (hi-lo)/2;
        if(target+rt[mid] >= a) hi = mid-1;
        else lo =mid+1;
    }
    return lo;
}