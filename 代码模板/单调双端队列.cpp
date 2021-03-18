// leetcode-239. Sliding Window Maximum
// Monotonous Deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> que;
        for(int i = 0; i < n; ++i){
            if(!que.empty() && que.front() == i - k) que.pop_front();
            while(!que.empty() && nums[i] > nums[que.back()]) que.pop_back();
            que.push_back(i);
            if(i >= k - 1) ans.push_back(nums[que.front()]);
        }
        return ans;
    }
};

// leetcode-1438. Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
// 维护两个mono queue，一个递增一个递减
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size(), ans = 0;
        int l = 0, r = 0, max_val = 0, min_val = INT_MAX;
        deque<int> max_seq, min_seq;
        while(r < n){
            while(max_seq.size() && nums[r] >= nums[max_seq.back()]) max_seq.pop_back();
            while(min_seq.size() && nums[r] <= nums[min_seq.back()]) min_seq.pop_back();
            max_seq.push_back(r);
            min_seq.push_back(r);
            
            while(l <= r && nums[max_seq.front()] - nums[min_seq.front()] > limit){
                if(max_seq.front() == l) max_seq.pop_front();
                if(min_seq.front() == l) min_seq.pop_front();
                ++l;
            }
            
            ans = max(ans, r - l + 1);
            
            ++r;
        }
        
        return ans;
    }
};