// leetcode-74. Search a 2D Matrix
// 两种解法

// solution1
// 每次消去一行或一列
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
        
        int row  = 0, col = n - 1;
        while(row < m && col >= 0){
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] > target) --col;
            else ++row;
        }
        return false;
    }
};

// solution2
// binary search
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0) return false;
        int n = matrix[0].size();
        if(n == 0) return false;
    
        int l = 0, r = m;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(matrix[mid][0] == target) return true;
            else if(matrix[mid][0] < target) l = mid + 1;
            else r = mid;
        }
        int row = l - 1;
        if(row < 0) return false;
        l = 0, r = n;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] < target) l = mid + 1;
            else r = mid;
        }
        return false;
    }
};