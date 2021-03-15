// leetcode-498. Diagonal Traverse
// Z字形对角线遍历
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        if(n == 0) return {};
        
        vector<int> ans(m * n);
        int row = 0, col = 0, d = 1;
        for(int i = 0; i < m * n; ++i){
            ans[i] = matrix[row][col];
            row -= d;
            col += d;
            
            if(row >= m) row = m - 1, col += 2, d = -d;
            if(col >= n) col = n - 1, row += 2, d = -d;
            if(row < 0) row = 0, d = -d;
            if(col < 0) col = 0, d = -d;
        }
        return ans;
    }
};

// leetcode-766. Toeplitz Matrix
// 常规对角线遍历
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; ++i){
            int val = matrix[i][0];
            int row = i, col = 0;
            while(row < m && col < n){
                if(matrix[row++][col++] != val) return false;
            }
        }
        
        for(int j = 0; j < n; ++j){
            int val = matrix[0][j];
            int row = 0, col = j;
            while(row < m && col < n){
                if(matrix[row++][col++] != val) return false;
            }
        }
        return true;
    }
};