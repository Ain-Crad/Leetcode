// leetcode-47. Permutations II

// solution 1 --recommend
// reference: https://leetcode-cn.com/problems/zi-fu-chuan-de-pai-lie-lcof/solution/mian-shi-ti-38-zi-fu-chuan-de-pai-lie-hui-su-fa-by/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    void dfs(vector<int>& nums, int start){
        int n = nums.size();
        if(start == n - 1){
            ans.push_back(nums);
            return;
        }
        
        unordered_set<int> vis;
        for(int i = start; i < n; ++i){
            if(vis.count(nums[i])) continue;
            vis.insert(nums[i]);
            
            swap(nums[start], nums[i]);
            dfs(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};


// solution 2
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vis.resize(n, false);
        sort(nums.begin(), nums.end());
        vector<int> perm;
        solve(nums, perm);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    vector<bool> vis;
    void solve(vector<int> &nums, vector<int> &perm){
        if(perm.size() == nums.size()){
            ans.push_back(perm);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i -1] && !vis[i - 1]) continue; // keypoint
            if(!vis[i]){
                vis[i] = true;
                perm.push_back(nums[i]);
                solve(nums, perm);
                vis[i] = false;
                perm.pop_back();
            }
        }
    }
};