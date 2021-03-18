// leetcode-739. Daily Temperatures

// jump array解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; --i){
            int j = i + 1;
            while(j < n && T[j] <= T[i]){
                if(ans[j] > 0) j += ans[j]; // jump部分
                else j = n;
            }
            if(j == n) ans[i] = 0;
            else ans[i] = j - i;
        }
        return ans;
    }
};

//monotonic stack解法
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n, 0);
        
        stack<int> stk;
        int i = 0;
        while(i < n){
            if(stk.empty() || T[i] <= T[stk.top()]){
                stk.push(i++);
            }else{
                int idx = stk.top();
                stk.pop();
                ans[idx] = i - idx;
            }
        }
        return ans;
    }
};