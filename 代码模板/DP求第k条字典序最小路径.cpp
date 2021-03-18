// leetcode-1643. Kth Smallest Instructions

class Solution {
public:
    string kthSmallestPath(vector<int>& dst, int k) {
        int m = dst[0], n = dst[1];

        // 杨辉三角，用于查询组合数
        vector<vector<int>> table(m + n + 1);
        for(int i = 0; i < m + n + 1; ++i){
            table[i] = vector<int>(i + 1, 1);
            for(int j = 1; j < i; ++j){
                table[i][j] = table[i - 1][j - 1] + table[i - 1][j];
            }
        }
        
        string ans;
        while(m + n){
            if(n > 0 && table[m + n][n] >= k){
                --n;
                ans.push_back('H');
            }else if(table[m + n][n] < k){
                k -= table[m + n][n];
                ++n;
                ans.pop_back();
                --m;
                ans.push_back('V');
            }else{
                --m;
                ans.push_back('V');
            }
        }
        return ans;
    }
};