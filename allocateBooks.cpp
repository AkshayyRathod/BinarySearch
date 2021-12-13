bool isValid(vector<int> num, int count,int mid){
    int studentCount=1;
    int pagesSum=0;

    for(int i=0;i<num.size();i++){
        if(pagesSum + num[i] <= mid){
            pagesSum+=num[i];
        }
        else{
            studentCount++;
            pagesSum=num[i];
            if(studentCount > count || num[i] > mid){
                return false;
            }
        }
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    int low=0;
    int maxi=0;
    for(int i=0;i<A.size();i++){
        maxi+=A[i];
    }
    int high=maxi;
    int res=-1;

    while(low<high){
        int mid=low+(high-low)/2;

        if(isValid(A,B,mid)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
