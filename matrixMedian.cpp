int func(vector<int> &arr, int val){
    int len=0;
    int lo=0;
    int hi=arr.size()-1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(arr[mid] <= val){
            len=mid+1;
            lo=mid+1;
        }
        else
           hi=mid-1;
    }
    return len;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int lo=INT_MIN;
    int hi=INT_MAX;
    int n = A.size();
    int m = A[0].size(); 
    // int ans=-1;

   while(lo<=hi){
        int mid=lo+(hi-lo)/2;
 
        int count=0;
        for(int i=0;i<A.size();i++){
          count+=func(A[i],mid);
        }

        if(count<=(n*m)/2){
            // ans=mid;
            lo=mid+1;
        }
        else
           hi=mid-1;
    }
   return lo;
}
