class Solution {          //O(logN),O(1)
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low=0;
        int high=nums.size()-2;
        
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[mid^1]){ 
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return nums[low];
    }
};

// mid xor 1 give even index before that
//if its even youll get odd and if its odd you will get even