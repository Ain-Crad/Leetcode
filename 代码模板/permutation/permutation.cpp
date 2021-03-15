// leetcode-46. Permutations

// solution 1 --recommend
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        solve(nums, 0);
        return ans;
    }
    
private:
    vector<vector<int>> ans;
    void solve(vector<int> &nums, int start){
        int n = nums.size();
        if(start == n - 1){
            ans.push_back(nums);
        }
        for(int i = start; i < n; ++i){
            swap(nums[start], nums[i]);
            solve(nums, start + 1);
            swap(nums[start], nums[i]);
        }
    }
};

// solution 2
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> vis(nums.size(), false);
        vector<int> perm;
        solve(nums, ans, vis, perm);
        return ans;
    }
    
private:
    void solve(vector<int> &nums, vector<vector<int>> &ans, vector<bool> &vis, vector<int> &perm){
        int n = nums.size();
        if(perm.size() == n){
            ans.push_back(perm);
            return;
        }
        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                vis[i] = true;
                perm.push_back(nums[i]);
                solve(nums, ans, vis, perm);
                vis[i] = false;
                perm.pop_back();
            }    
        }
    }
};