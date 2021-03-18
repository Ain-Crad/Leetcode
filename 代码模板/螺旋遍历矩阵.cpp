class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m == 0) return {};
        int n = matrix[0].size();
        if(n == 0) return {};
        
        int t = 0, b = m - 1, l = 0, r = n - 1;
        int row, col;
        
        vector<int> ans;
        while(t <= b && l <= r){
            // go right
            row = t, col = l;
            while(t <= b && l <= r && col <= r) ans.push_back(matrix[row][col]), ++col;
            ++t;
            
            // go down
            row = t, col = r;
            while(t <= b && l <= r && row <= b) ans.push_back(matrix[row][col]), ++row;
            --r;
            
            // go left
            row = b, col = r;
            while(t <= b && l <= r && col >= l) ans.push_back(matrix[row][col]), --col;
            --b;
            
            // go up
            row = b, col = l;
            while(t <= b && l <= r && row >= t) ans.push_back(matrix[row][col]), --row;
            ++l;
        }
        return ans;
    }
};