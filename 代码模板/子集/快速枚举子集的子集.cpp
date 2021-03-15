// leetcode-1723. Find Minimum Time to Finish All Jobs
// referenece-https://leetcode-cn.com/problems/find-minimum-time-to-finish-all-jobs/solution/zhuang-ya-dp-jing-dian-tao-lu-xin-shou-j-3w7r/

// 枚举子集的子集 核心代码
// i 和 j 都为子集的 bitmask
for (int i = 0; i < (1 << n); ++i) {    // 枚举子集
    for (int j = i; j; j = (j - 1) & i) {   // 枚举子集的子集   
        // do something
    }
}

// 状态压缩DP + 快速枚举子集的子集
class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size();
        vector<int> tot(1 << n, 0);
        for(int i = 0; i < (1 << n); ++i){
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)) tot[i] += jobs[n - 1 - j];
            }
        }
        
        vector<vector<int>> dp(k, vector<int>(1 << n, 0));
        for(int i = 0; i < (1 << n); ++i) dp[0][i] = tot[i];

        for(int i = 1; i < k; ++i){
            for(int j = 0; j < (1 << n); ++j){
                int min_val = INT_MAX;
                for(int sub = j; sub; sub = (sub - 1) & j){
                    int left = j - sub;
                    int val = max(dp[i - 1][left], tot[sub]);
                    min_val = min(min_val, val);
                }
                dp[i][j] = min_val;
            }
        }
        return dp[k - 1][(1 << n) - 1];
    }
};