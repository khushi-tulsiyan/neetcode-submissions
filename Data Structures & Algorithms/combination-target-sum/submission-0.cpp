class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        combsum(0, nums, target, cur);
        return res;
    }
    private:
    void combsum(int i, vector<int> &nums, int target, vector<int> &cur){
        if(target == 0){
            res.push_back(cur);
            return;
        }

        if(target < 0 || i>=nums.size()){
            return;
        }

        cur.push_back(nums[i]);
        combsum(i, nums, target-nums[i], cur);
        cur.pop_back();
        combsum(i+1, nums,target, cur);
    }
};
