// 10. 正则表达式匹配

// 解析：卡住的点是不知道如何处理 '*', 觉得遍历到每个字符还要检查一下它的后面是否有'*'太麻烦了，
// 但是如果是从后往前匹配的话，这个问题可以轻松解决，如果当前字符是'*'的话就往前多遍历一个字符
// 这样dfs递归来解的话就很符合常规思维了，递归找到转移的思路后，就可以很容易的写出bottom-up的 dp方程。

class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;

        auto match = [&](int i, int j){
            if(i < 0) return false;
            return p[j] == '.' || s[i] == p[j];
        };

        for(int i = 0; i <= m; ++i){
            for(int j = 1; j <= n; ++j){
                if(p[j - 1] != '*'){
                    dp[i][j] = match(i - 1, j - 1) && dp[i - 1][j - 1];
                }else{
                    if(!match(i - 1, j - 2)) dp[i][j] = dp[i][j - 2];
                    else dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                }
            }
        }

        return dp[m][n];
    }
};