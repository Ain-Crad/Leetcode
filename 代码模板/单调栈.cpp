// leetcode-503. Next Greater Element II

// solution1
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        int i = 0;
        while(i < 2 * n){
            if(stk.empty() || nums[i % n] <= nums[stk.top()]){
                if(i < n) stk.push(i++);
                else i++;
            }else{
                if(stk.empty()) break;
                int idx = stk.top();
                stk.pop();
                ans[idx] = nums[i % n];
            }
        }
        return ans;
    }
};

// solution2
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> stk;
        for(int i = 0; i < 2 * n; ++i){
            while(stk.size() && nums[i % n] > nums[stk.top()]){
                ans[stk.top()] = nums[i % n];
                stk.pop();
            }
            stk.push(i % n);
        }
        return ans;
    }
};


// leetcode-496. Next Greater Element I
// 单调递减栈

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> mp;
        int n = nums2.size(), i = 0;
        while(i < n){
            if(stk.empty() || nums2[i] < stk.top()){
                stk.push(nums2[i++]);
            }
            else{
                int left = stk.top();
                stk.pop();
                mp[left] = nums2[i];
            }
        }
        
        vector<int> ans;
        for(int i = 0; i < nums1.size(); ++i){
            if(mp.count(nums1[i])) ans.push_back(mp[nums1[i]]);
            else ans.push_back(-1);
        }
        return ans;
    }
};

// leetcode-42. Trapping Rain Water
// 单调递减栈

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if(n <= 2) return 0;
        stack<int> stk;
        int ans = 0;
        int i = 0;
        while(i < n){
            if(stk.empty() || height[i] < height[stk.top()]){
                stk.push(i++);
            }else{
                int bar = stk.top();
                stk.pop();
                if(stk.empty()) continue;
                int left = stk.top();
                int h = min(height[left], height[i]) - height[bar];
                int w = i - left - 1;
                ans += h * w;
            }
        }
        
        return ans;
    }
};