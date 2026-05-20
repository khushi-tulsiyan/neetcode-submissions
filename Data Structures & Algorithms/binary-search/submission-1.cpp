class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size();

        while(start < end){
            int mid = start + (end  - start) /2;
            if(nums[mid] > target){
                end = mid;
            } else{
                start = mid + 1;
            }
        } 
        return (start > 0 && target == nums[start - 1])? start - 1: -1;
    } 
};
