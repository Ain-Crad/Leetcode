// leetcode-254. 因子的组合

class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ans;
        vector<int> vec;
        dfs(ans, vec, n, n);
        return ans;
    }

private:
    void dfs(vector<vector<int>>& ans, vector<int>&vec, int n, int cur){
        if(cur < n){
            vec.push_back(cur);
            ans.push_back(vec);
            vec.pop_back();
        }
        
        for(int i = 2; i * i <= cur; ++i){
            // i >= vec.back()保证因子的有序，可以天然去重
            if(cur % i == 0 && (vec.empty() || i >= vec.back())){
                vec.push_back(i);
                dfs(ans, vec, n, cur / i);
                vec.pop_back();
            }
        }
    }
};