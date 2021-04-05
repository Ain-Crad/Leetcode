class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> sub;
        vector<vector<int>> ans;
        dfs(nums, 0, sub, ans);
        return ans;
    }

private:
    void dfs(vector<int>& nums, int start, vector<int>& sub, vector<vector<int>>& ans){
        ans.push_back(sub);

        int n = nums.size();
        for(int i = start; i < n; ++i){
            if(i > start && nums[i] == nums[i - 1]) continue;
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, ans);
            sub.pop_back();
        }
    }
};