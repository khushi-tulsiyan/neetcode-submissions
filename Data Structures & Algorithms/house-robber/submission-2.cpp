class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(nums, 0, dp);
    }

    int dfs(vector<int> &nums, int i, vector<int> &dp){
        if(i>=nums.size())
        return 0;

        if(dp[i] != -1)
        return dp[i];

        dp[i] = max(dfs(nums, i+1, dp), nums[i] + dfs(nums, i+2, dp));

        return dp[i];
    }
};
