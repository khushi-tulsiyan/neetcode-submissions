class Solution {
public:
    int search(vector<int>& nums, int target) {
        int r = nums.size();
        int l = 0;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return (l > 0 && nums[l - 1] == target) ? l - 1: -1; 
        
    } 
};
