class Solution {
public:
    
int getPivot(vector<int>& num){
    int low=0;
    int high=num.size()-1;
    int mid=low+(high-low)/2;
  
    while(low<high){
        if(num[mid] >= num[0]){
            low=mid+1;
        }
        else{
         high=mid;
        }
       mid=low+(high-low)/2;
    }
    return low;
}
    
    int binarySearch(vector<int>& num,int start, int end, int key){
         int low=start;
         int high=end;
        
        while(low<=high){
            int  mid=low+(high-low)/2;
            if(num[mid]==key){
                return mid;
            }
            else if(key>=num[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
             mid=low+(high-low)/2;
        }
      return -1;
    }

    
    
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int pivot=getPivot(nums);
        if(nums[n-1] >= target >= nums[pivot]){
          return  binarySearch(nums,pivot,n-1,target);
        }
        else{
            return binarySearch(nums,0,pivot-1,target);
        }
    }
};

//2nd approach
class Solution {
public:
    int search(vector<int>& a, int target) {
        int low = 0, high = a.size() - 1; 
        while(low <= high) {
            int mid = (low + high) >> 1; 
            if(a[mid] == target) return mid; 
            
            // the left side is sorted
            if(a[low] <= a[mid]) {
                if(target >= a[low] && target <= a[mid]) {
                    high = mid - 1; 
                }
                else {
                    low = mid + 1; 
                }
            }
            else {
                if(target >= a[mid] && target <= a[high]) {
                    low = mid + 1; 
                }
                else {
                    high = mid - 1; 
                }
            }
        } 
        return -1; 
    }
};