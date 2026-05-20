class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s = 0, e = nums.size();

        while(s < e){
            int m = s + (e-s) / 2;
            if(nums[m] > target){
                e = m;
            } else {
                s = m + 1;
            }
        }
        return (s > 0 && target == nums[s - 1]) ? s - 1: -1;
    }
};
