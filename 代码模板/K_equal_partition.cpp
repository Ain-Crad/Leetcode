// leetcode-698. Partition to K Equal Sum Subsets

// solution1
class Solution {
public:
 bool canPartitionKSubsets(vector<int>& nums, int k) {
     int n = nums.size(), sum = 0, max_val = 0;
     for(int &v : nums) sum += v, max_val = max(max_val, v);
     
     if(sum % k || max_val > sum / k) return false;
     
     vis.resize(n, false);
     return dfs(nums, k, 0, sum / k, 0);
 }
    
private:
    vector<bool> vis;
    bool dfs(vector<int> &nums, int k, int idx, int tar, int cur){
        if(k == 1) return true;
        if(cur == tar) return dfs(nums, k - 1, 0, tar, 0);
        
        for(int i = idx; i < nums.size(); ++i){
            if(vis[i]) continue;
            vis[i] = true;
            if(dfs(nums, k, i + 1, tar, cur + nums[i])) return true;
            vis[i] = false;
        }
        return false;
    }
};

// solution2
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0, max_val = 0;
        for(int &v : nums) sum += v, max_val = max(max_val, v);
        
        if(sum % k || max_val > sum / k) return false;
        
        sort(nums.begin(), nums.end(), greater<int>());
        
        int tar = sum / k;
        vector<int> vec(k, 0);
        return dfs(nums, vec, 0, tar);
    }
    
private:
    bool dfs(vector<int> &nums, vector<int> &vec, int idx, int tar){
        if(idx == nums.size()) return true;
        
        for(int i = 0; i < vec.size(); ++i){
            if(vec[i] + nums[idx] > tar) continue;
            vec[i] += nums[idx];
            if(dfs(nums, vec, idx + 1, tar)) return true;
            vec[i] -= nums[idx];
        }
        return false;
    }
};