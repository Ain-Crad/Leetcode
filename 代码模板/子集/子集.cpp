// iterative
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        int n = nums.size();
        for(int i = 0; i < (1 << n); ++i){
            sub.clear();
            for(int j = 0; j < n; ++j){
                if(i & (1 << j)) sub.push_back(nums[j]);
            }
            subs.push_back(sub);
        }
        
        return subs;
    }
};


// backtracing solution1
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        dfs(nums, 0, sub, subs);
        return subs;
    }
    
private:
    void dfs(vector<int>&nums, int idx, vector<int>& sub, vector<vector<int>>& subs){
        if(idx == nums.size()){
            subs.push_back(sub);
            return;
        }
        
        sub.push_back(nums[idx]);
        dfs(nums, idx + 1, sub, subs);
        sub.pop_back();
        dfs(nums, idx + 1, sub, subs);
    }
};

// backtracing solution2
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subs;
        vector<int> sub;
        dfs(nums, 0, sub, subs);
        return subs;
    }
    
private:
    void dfs(vector<int>&nums, int start, vector<int>& sub, vector<vector<int>>& subs){
        subs.push_back(sub);
        for(int i = start; i < nums.size(); ++i){
            sub.push_back(nums[i]);
            dfs(nums, i + 1, sub, subs);
            sub.pop_back();
        }
    }
};