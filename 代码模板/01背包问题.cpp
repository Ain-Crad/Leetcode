// leetcode-416. Partition Equal Subset Sum

// dfs + memo -- top down
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        sum /= 2;
        int n = nums.size();
        dp.resize(n, vector<int>(sum + 1, -1));
        return dfs(nums, 0, sum);
    }
    
private:
    vector<vector<int>> dp;
    bool dfs(vector<int> &nums, int idx, int target){
        if(target == 0) return true;
        if(target < 0) return false;
        if(idx >= nums.size()) return false;
        
        if(dp[idx][target] != -1) return dp[idx][target];
        bool ans = dfs(nums, idx + 1, target) || dfs(nums, idx + 1, target - nums[idx]);
        return dp[idx][target] = ans;
    }
};

// dp -- bottom up
// dp关键是想出状态转移的方程，然后根据方程画表格确定递推的方向，以及后续的内存优化
// 对于背包问题的状态转移方程，以本题为例，是要判断 n 个数中是否能够找到一个子集满足和为target，
// 那么可以由前 n - 1个数种是否能够满足target 或 前 n - 1个数种是否满足 target - nums[n]来判断
// 相当于取或者不取第 n 个数两种情况，和递归的形式是对应的。
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int n = nums.size();
        sum /= 2;
        vector<vector<int>> dp(n, vector<int>(sum + 1, false));
        for(int i = 0; i < n; ++i) dp[i][0] = true;
        if(nums[0] <= sum) dp[0][nums[0]] = true;

        for(int i = 1; i < n; ++i){
            for(int j = 1; j <= sum; ++j){
                dp[i][j] |= dp[i-1][j];
                if(j >= nums[i]) dp[i][j] |= dp[i - 1][j - nums[i]];
            }
        }
        return dp[n - 1][sum];
    }
};

// dp内存优化
// 画出表格之后内存优化很容易判断
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) return false;
        int n = nums.size();
        sum /= 2;
        vector<int> dp(sum + 1, false);
        dp[0] = true;

        for(int i = 1; i < n; ++i){
            for(int j = sum; j >= 1; --j){
                if(j >= nums[i]) dp[j] |= dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};